#!/bin/bash
set -euo pipefail

: "${DOMAIN_NAME:?DOMAIN_NAME must be set}"

if [ ! -x /opt/portainer/portainer ]; then
    echo "Portainer binary is missing or not executable" >&2
    exit 1
fi

if [ ! -r /run/secrets/portainer_admin_password ]; then
    echo "Portainer administrator password secret is unavailable" >&2
    exit 1
fi

if [ ! -S /var/run/docker.sock ]; then
    echo "Approved Docker socket mount is unavailable" >&2
    exit 1
fi

mkdir -p /data

exec /opt/portainer/portainer \
    --host unix:///var/run/docker.sock \
    --bind :9000 \
    --base-url /portainer \
    --trusted-origins "$DOMAIN_NAME" \
    --admin-password-file /run/secrets/portainer_admin_password
