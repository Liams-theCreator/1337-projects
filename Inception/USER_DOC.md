# User Documentation

## Purpose

This guide explains how to operate the Inception stack after it has been configured. Run every command from the repository root, the directory that contains the `Makefile`.

## Available Services

| Service | What it provides | How to access it |
|---|---|---|
| WordPress | The main website and content-management system | `https://imellali.42.fr/` |
| WordPress administration | Create and manage site content | `https://imellali.42.fr/wp-admin/` |
| Static website | A simple Inception project page | `https://imellali.42.fr/static/` |
| Adminer | Browser-based MariaDB administration | `https://imellali.42.fr/adminer/` |
| Portainer | Browser-based Docker container management | `https://imellali.42.fr/portainer/` |
| FTP | File transfer to the WordPress file volume | FTP port `21`, with passive ports `21000-21010` |
| Redis | Internal WordPress object cache | Internal only; no browser or direct host access. |

NGINX is the public HTTPS gateway. MariaDB, WordPress/PHP-FPM, Redis, the static site, Adminer, and Portainer are private Docker-network services. Do not expect their internal ports to be reachable from the VM host.

## Start, Stop, and Restart

Use the Makefile for normal operation:

```bash
make up
make ps
make stop
make start
make restart
make down
make re
```

`make up` builds when necessary and starts the complete stack. `make stop` stops the containers without removing them. `make down` removes containers and the project network but keeps persistent data. `make re` performs a safe recreation while preserving the named volumes.

To control one service, append `SERVICE=<name>`:

```bash
make restart SERVICE=wordpress
make logs SERVICE=nginx
make stop SERVICE=portainer
make start SERVICE=portainer
```

Available names are `mariadb`, `wordpress`, `nginx`, `redis`, `ftp`, `static_site`, `adminer`, and `portainer`.

> Avoid `docker compose down -v` and do not remove `/home/imellali/data/` unless you intentionally want to discard the database, WordPress files, or Portainer configuration.

## Website and Administration Access

### WordPress

Open `https://imellali.42.fr/` for the website. Use `https://imellali.42.fr/wp-admin/` for the WordPress dashboard.

The administrator username is `site_owner`. The standard WordPress account is `editor` and has the **subscriber** role. Passwords are local secrets; see the next section. A self-signed development certificate can cause a browser warning, which is expected in this local VM setup.

### Adminer

Open `https://imellali.42.fr/adminer/` and use the following values:

| Field | Value |
|---|---|
| System | MariaDB |
| Server | `mariadb` |
| Username | `wp_user` |
| Password | Contents of `secrets/db_password.txt` |
| Database | `wordpress` |

The MariaDB root account is intentionally socket-only inside the MariaDB container. Do not try to use it through Adminer.

### Portainer

Open `https://imellali.42.fr/portainer/`. The initial Portainer account is `admin`; its password is stored in `secrets/portainer_admin_password.txt`. This account can manage the Docker environment through the approved Docker socket mount, so treat it as highly privileged.

If desired, create a separate Portainer user named `imellali`, promote it to Administrator, test that login, and retain the original `admin` account as a recovery account. Do not share either account.

### FTP

Use an FTP client inside the VM with the following settings:

| Setting | Value |
|---|---|
| Host | `127.0.0.1` when using the FTP client inside the VM |
| Port | `21` |
| Encryption | Plain FTP for this local exercise |
| Transfer mode | Passive |
| Username | Value of `FTP_USER` in `srcs/.env` |
| Password | Contents of `secrets/ftp_password.txt` |

The FTP account writes to the same persistent volume used by WordPress. Upload only intended website files. If the client is outside the VM, update `FTP_PASV_ADDRESS` to an address reachable by that client and ensure the network policy permits ports `21` and `21000-21010`.

## Credentials and Local Configuration

The repository does not contain real passwords. Local credentials are stored in ignored files under `secrets/`:

| File | Used by |
|---|---|
| `db_root_password.txt` | MariaDB internal root initialization and local database maintenance. |
| `db_password.txt` | WordPress and Adminer database account. |
| `wp_admin_password.txt` | WordPress `site_owner` account. |
| `wp_standard_password.txt` | WordPress `editor` subscriber account. |
| `redis_password.txt` | Redis and WordPress object-cache connection. |
| `ftp_password.txt` | FTP account. |
| `portainer_admin_password.txt` | Initial Portainer administrator account. |

Use a terminal only on the trusted VM to read a credential, for example:

```bash
cat secrets/wp_admin_password.txt
```

Never paste credentials into chat, screenshots, Dockerfiles, Compose files, commits, or issues. Keep the secret directory readable only by your local user.

## Check That the Stack Is Healthy

Begin with:

```bash
make ps
```

All eight services should show `Up`. Only NGINX should show port `443`; FTP should show its required passive FTP ports. The other services show an internal container port only.

Check the public routes through the TLS gateway:

```bash
for route in / /static/ /adminer/ /portainer/; do
  curl -k -sS -o /dev/null -w "${route}=%{http_code}\n" \
    --resolve imellali.42.fr:443:127.0.0.1 \
    "https://imellali.42.fr${route}"
done
```

Each route should return `200`. Use logs to investigate a service without exposing a secret:

```bash
make logs SERVICE=wordpress
make logs SERVICE=nginx
make logs SERVICE=portainer
```

For deeper maintenance, persistent-data locations, and targeted rebuilds, read [DEV_DOC.md](DEV_DOC.md).
