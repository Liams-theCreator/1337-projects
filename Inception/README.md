*This project has been created as part of the 42 curriculum by imellali.*

# Inception

## Description

Inception is a system-administration project that builds a small web infrastructure inside a Debian virtual machine using Docker Compose. Rather than relying on ready-made service images, every service is built from a project Dockerfile based on Debian Bookworm. The stack provides a TLS-protected WordPress site backed by MariaDB and is extended with Redis object caching, FTP access to WordPress files, a static project page, Adminer, and Portainer.

The architecture deliberately separates responsibilities. NGINX is the sole public HTTPS gateway on port `443`; WordPress/PHP-FPM, MariaDB, Redis, Adminer, the static site, and Portainer communicate on a private Docker bridge network. FTP intentionally exposes its control and passive-data ports because an FTP client outside the Docker network needs them. Docker secrets keep credentials outside the tracked source, while named volumes preserve the database, WordPress files, and Portainer configuration below `/home/imellali/data`.

## Services and Design

| Service | Responsibility | Access model |
|---|---|---|
| NGINX | TLS 1.2/1.3 termination and routing | The only public web entrypoint: `443`. |
| WordPress + PHP-FPM | Dynamic website and PHP execution | Private FastCGI service on `9000`. |
| MariaDB | WordPress relational database | Private database service on `3306`. |
| Redis | Authenticated WordPress object cache | Private service on `6379`. |
| FTP | Managed file transfer to the WordPress volume | Ports `21` and `21000-21010` for passive FTP. |
| Static site | Project page | Reached through NGINX at `/static/`. |
| Adminer | Database administration interface | Reached through NGINX at `/adminer/`. |
| Portainer | Docker management dashboard | Reached through NGINX at `/portainer/`. |

Every service has its own Dockerfile. Container lifecycle scripts validate required runtime inputs and use `exec` to replace the shell with the service process, allowing Docker to supervise that process as PID 1. The Compose file applies `restart: unless-stopped` to the services.

### Source Layout

| Path | Purpose |
|---|---|
| `Makefile` | Main project interface for building, starting, stopping, and inspecting the stack. |
| `srcs/docker-compose.yml` | Defines services, images, networking, named volumes, and Docker secrets. |
| `srcs/requirements/` | Dockerfiles, NGINX/PHP-FPM/vsftpd configuration, entrypoints, and static-site source. |
| `secrets/` | Local, ignored password files. Never commit this directory. |
| `/home/imellali/data/` | Host-side backing directories used by the named persistent volumes. |
| `USER_DOC.md` | Operational guide for a user or administrator. |
| `DEV_DOC.md` | Rebuild, maintenance, and debugging guide for a developer. |

## Key Technical Choices

### Virtual Machines vs Docker

A virtual machine virtualizes hardware and runs its own guest operating system. In this project, the Debian VM provides the isolated operating-system environment required by the subject. Docker runs inside that VM and uses the guest kernel to isolate lighter-weight containers. The VM provides a stable boundary from the physical host, while Docker packages each infrastructure service and its dependencies reproducibly.

### Secrets vs Environment Variables

Environment variables are appropriate for non-confidential configuration such as the domain name, database name, service host names, and port numbers. They are stored locally in `srcs/.env`, which is ignored by Git. Passwords are Docker secrets stored as local files under `secrets/` and mounted read-only under `/run/secrets/` only for services that need them. This avoids placing passwords in Dockerfiles, Compose values, or the repository history.

### Docker Bridge Network vs Host Network

`inception_network` is a user-defined bridge network. It gives services private DNS names such as `mariadb` and `wordpress` and exposes no service to the VM host unless Compose explicitly publishes a port. Host networking would remove that port-isolation boundary and is prohibited by the subject. Only NGINX publishes `443` for web access; FTP publishes the additional ports required by the bonus feature.

### Docker Named Volumes vs Bind Mounts

The mandatory persistent data is managed as Docker **named volumes**: `mariadb_data` and `wordpress_data`. Compose configures Docker's local volume driver to back those volumes with directories below `/home/imellali/data`, satisfying both persistence and host-location requirements. Services reference volume names rather than raw host paths. Direct bind mounts are used only where a service requires a host control interface, notably the approved Portainer mount of `/var/run/docker.sock`.

## Instructions

### Prerequisites

Use a Debian Linux virtual machine with Docker Engine, the Docker Compose plugin, GNU Make, OpenSSL, and Git installed. Configure the domain `imellali.42.fr` to resolve to the VM's local address. The detailed first-time setup is in [DEV_DOC.md](DEV_DOC.md).

Create the local configuration and secret files before building. They are intentionally excluded from Git. Do not copy passwords into this README, Dockerfiles, Compose files or commits.

### Build and Start

Run commands from the repository root:

```bash
make build
make up
make ps
```

`make up` builds the custom images when necessary and starts the complete stack in detached mode. `make ps` confirms service states and published ports.

### Stop and Recreate

```bash
make stop
make start
make restart
make down
make re
```

`make down` removes containers and the project network but preserves the named volumes and their data. `make re` performs a down/up cycle while preserving the volumes. Do not use `docker compose down -v` unless deliberately performing a destructive clean test or discarding all persistent state.

### Web and Administration URLs

| Endpoint | Purpose |
|---|---|
| `https://imellali.42.fr/` | WordPress site. |
| `https://imellali.42.fr/wp-admin/` | WordPress administration interface. |
| `https://imellali.42.fr/static/` | Static Inception roadmap page. |
| `https://imellali.42.fr/adminer/` | Adminer database interface. |
| `https://imellali.42.fr/portainer/` | Portainer Docker management dashboard. |

The development TLS certificate is self-signed, so a browser may display a certificate warning. The expected secure protocols are TLS 1.2 and TLS 1.3.

## Validation Summary

The stack has been checked for private service ports, the NGINX-only HTTPS gateway, TLS support, named-volume locations, WordPress installation and roles, Redis connectivity, FTP shared-volume transfer, and the `200` status of the four HTTPS routes. Portainer additionally uses a persistent `portainer_data` named volume and a deliberate, privileged Docker socket mount. Only trusted administrators should be allowed to use its dashboard.

For day-to-day checks and troubleshooting, read [USER_DOC.md](USER_DOC.md). For source layout, configuration, targeted rebuilds, persistence, and developer checks, read [DEV_DOC.md](DEV_DOC.md).

## Resources

The following references were used to understand and implement the infrastructure:

1. [Docker overview](https://docs.docker.com/get-started/docker-overview/)
2. [Dockerfile reference](https://docs.docker.com/reference/dockerfile/)
3. [Docker secrets](https://docs.docker.com/engine/swarm/secrets/)
4. [Docker networking](https://docs.docker.com/engine/network/)
5. [Docker volumes](https://docs.docker.com/engine/storage/volumes/)
6. [Docker Compose reference](https://docs.docker.com/reference/compose-file/)
7. [NGINX documentation](https://nginx.org/en/docs/)
8. [WordPress documentation](https://wordpress.org/documentation/)
9. [MariaDB documentation](https://mariadb.com/kb/en/documentation/)
10. [Redis documentation](https://redis.io/docs/latest/)
11. [vsftpd documentation](https://security.appspot.com/vsftpd.html)
12. [Adminer](https://www.adminer.org/)
13. [Portainer documentation](https://docs.portainer.io/)

### AI Use Disclosure

AI was used as a learning and productivity aid. It assisted with explaining Docker, networking, PID 1, foreground processes, secrets, volume persistence, and service boundaries; reviewing configuration structure; and drafting this documentation. All generated material was reviewed, adapted to the project constraints, and tested in the Debian VM by the project author. The author remains responsible for understanding and defending every design choice and command used in the project.
