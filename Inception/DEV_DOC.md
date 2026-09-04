# Developer Documentation

## Scope

This guide describes how to configure, build, maintain, and validate the Inception stack from a fresh Debian VM. It covers the tracked source only; real values in `srcs/.env` and `secrets/` must remain local and ignored by Git.

## Prerequisites

Use a Debian Linux virtual machine with the following available:

| Requirement | Why it is required |
|---|---|
| Docker Engine and Docker Compose v2 plugin | Builds and orchestrates the project containers. |
| GNU Make | Provides the project interface. |
| OpenSSL | Generates local random secrets. |
| Git | Clones, audits, and publishes the project source. |
| curl | Tests HTTPS and FTP access. |
| A local mapping for `imellali.42.fr` | Lets the browser and test commands reach the VM. |

Clone the repository and enter it:

```bash
git clone https://github.com/Liams-theCreator/docker_fund.git
cd docker_fund
```

For local VM testing, make the project domain resolve to the VM loopback address when appropriate:

```bash
sudo sh -c 'printf "127.0.0.1 imellali.42.fr\n" >> /etc/hosts'
```

Do not add duplicate entries if the mapping already exists. In a different network design, point the domain at the VM address that receives the HTTPS traffic.

## Prepare Persistent Data Directories

The project uses Docker named volumes backed by these required host directories:

```bash
mkdir -p \
  /home/imellali/data/mariadb \
  /home/imellali/data/wordpress \
  /home/imellali/data/portainer
```

Compose defines `mariadb_data`, `wordpress_data`, and `portainer_data` with the Docker local volume driver. Docker manages the volume names, while the backing directories make persistence visible below `/home/imellali/data`.

## Create Local Configuration

Create the ignored environment file at `srcs/.env`. It contains non-secret operational values. Adapt only the values that match your local VM and domain:

```dotenv
DOMAIN_NAME=imellali.42.fr

DB_NAME=wordpress
DB_USER=wp_user
DB_HOST=mariadb

WP_TITLE=Inception WordPress
WP_ADMIN_USER=site_owner
WP_ADMIN_EMAIL=site_owner@imellali.42.fr
WP_STANDARD_USER=editor
WP_STANDARD_EMAIL=editor@imellali.42.fr

REDIS_HOST=redis
REDIS_PORT=6379

FTP_USER=ftp_user
FTP_PASV_ADDRESS=127.0.0.1
```

`FTP_PASV_ADDRESS=127.0.0.1` is appropriate when the FTP client runs inside the same VM. When an FTP client connects from outside the VM, set it to the reachable VM address and confirm the passive port range is permitted.

## Create Local Secrets

Create the ignored secret directory and generate one file per credential. The commands below generate values without printing them:

```bash
mkdir -p secrets
umask 077

for secret in \
  db_root_password \
  db_password \
  wp_admin_password \
  wp_standard_password \
  redis_password \
  ftp_password \
  portainer_admin_password
do
  openssl rand -base64 32 > "secrets/${secret}.txt"
done

chmod 600 secrets/*.txt
```

Verify that Git ignores every secret without revealing its contents:

```bash
git check-ignore -v --no-index secrets/*.txt srcs/.env
git ls-files | grep -E '(^|/)(\.env|secrets/)|password\.txt|\.(key|crt)$' || true
```

> Do not use placeholder passwords in committed files. Do not echo a secret into shell history, logs, screenshots, or chat.

## Build and Launch

The Makefile calls `docker compose -f srcs/docker-compose.yml` for normal lifecycle commands.

```bash
make build
make up
make ps
```

`make up` runs `docker compose ... up -d --build`. The first launch creates the named volumes and initializes MariaDB and WordPress. The entrypoints are idempotent: later starts use the persisted state instead of reinstalling the database or website.

Render the Compose configuration directly when diagnosing syntax or interpolation:

```bash
docker compose -f srcs/docker-compose.yml config
```

## Architecture and Data Flow

| Component | Build source | Runtime relationship |
|---|---|---|
| MariaDB | `srcs/requirements/mariadb/` | Initializes the `wordpress` database and `wp_user`; stores data in `mariadb_data`. |
| WordPress | `srcs/requirements/wordpress/` | Waits for MariaDB and Redis; runs PHP-FPM; stores application files in `wordpress_data`. |
| NGINX | `srcs/requirements/nginx/` | Terminates TLS on `443`, serves WordPress via FastCGI, and routes bonus interfaces. |
| Redis | `srcs/requirements/bonus/redis/` | Provides authenticated, non-persistent WordPress object caching. |
| FTP | `srcs/requirements/bonus/ftp/` | Shares `wordpress_data` for managed passive FTP file transfer. |
| Static site | `srcs/requirements/bonus/static-site/` | Serves static content internally; NGINX routes `/static/`. |
| Adminer | `srcs/requirements/bonus/adminer/` | Runs PHP-FPM internally; NGINX routes `/adminer/`. |
| Portainer | `srcs/requirements/bonus/portainer/` | Stores state in `portainer_data`; NGINX routes `/portainer/`; manages Docker through the approved socket. |

The bridge network `inception_network` supplies private service DNS. NGINX is the only web service that publishes host port `443`. FTP additionally publishes its control port and passive range because an FTP client must reach those ports from outside the Docker network.

## Routine Management Commands

| Task | Command |
|---|---|
| Build all custom images | `make build` |
| Start or update complete stack | `make up` |
| Show state and exposed ports | `make ps` |
| View all logs | `make logs` |
| View one service log | `make logs SERVICE=wordpress` |
| Stop one service | `make stop SERVICE=redis` |
| Start one service | `make start SERVICE=redis` |
| Restart one service | `make restart SERVICE=nginx` |
| Remove containers and network while retaining data | `make down` |
| Recreate full stack while retaining data | `make re` |

For an isolated rebuild while the rest of the stack remains running:

```bash
docker compose -f srcs/docker-compose.yml up -d --build --force-recreate --no-deps <service>
```

Replace `<service>` with one of the Compose service names. Use this only when the dependency relationship is understood; a full `make up` is simpler after broad source changes.

## Persistence, Backup, and Reset

| Named volume | Container path | Host-backed location | Contents |
|---|---|---|---|
| `mariadb_data` | `/var/lib/mysql` | `/home/imellali/data/mariadb` | MariaDB tables and database state. |
| `wordpress_data` | `/var/www/html` | `/home/imellali/data/wordpress` | WordPress core, configuration, uploads, plugins, and themes. |
| `portainer_data` | `/data` | `/home/imellali/data/portainer` | Portainer database, keys, and settings. |

Use the following to confirm the mapping:

```bash
docker volume inspect mariadb_data wordpress_data portainer_data \
  --format '{{.Name}} -> {{index .Options "device"}}'
```

For a consistent filesystem backup, stop the stack first, then archive `/home/imellali/data` and separately protect the local `secrets/` directory. Never add either secret values or a private backup archive to Git.

```bash
make down
tar -czf "$HOME/inception-data-backup.tar.gz" -C /home/imellali data
```

A destructive clean evaluation resets images, containers, volume metadata, and host-backed data only after a verified backup or VM snapshot exists. Do not use destructive commands during routine development.

## Portainer Security Note

Portainer mounts `/var/run/docker.sock` read-write so that it can inspect and manage the Docker engine. This is a deliberate privileged exception: a Portainer administrator can control Docker resources on the VM. Limit dashboard access to trusted local administrators, retain strong local credentials, and do not expose Portainer directly on a host port. It is available only through the existing NGINX TLS route at `/portainer/`.

## Developer Validation Commands

Check process state, privacy, and public routes without displaying secrets:

```bash
make ps

docker inspect mariadb wordpress redis static_site adminer portainer \
  --format '{{.Name}} ports={{json .NetworkSettings.Ports}}'

for route in / /static/ /adminer/ /portainer/; do
  curl -k -sS -o /dev/null -w "${route}=%{http_code}\n" \
    --resolve imellali.42.fr:443:127.0.0.1 \
    "https://imellali.42.fr${route}"
done
```

The expected route status is `200`. Private services should not be reachable directly on the VM host. Use `docker compose -f srcs/docker-compose.yml logs --tail=100 <service>` to investigate a specific failure.

## References

1. [Docker Compose reference](https://docs.docker.com/reference/compose-file/)
2. [Docker volumes](https://docs.docker.com/engine/storage/volumes/)
3. [Docker networking](https://docs.docker.com/engine/network/)
4. [Dockerfile reference](https://docs.docker.com/reference/dockerfile/)
5. [Portainer Docker installation](https://docs.portainer.io/start/install-ce/server/docker/linux)
6. [Portainer CLI configuration options](https://docs.portainer.io/advanced/cli)
