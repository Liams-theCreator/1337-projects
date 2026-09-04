#!/bin/bash
set -euo pipefail

: "${REDIS_PASSWORD_FILE:?REDIS_PASSWORD_FILE is required}"

if [ ! -r "$REDIS_PASSWORD_FILE" ]; then
    echo "Missing readable Redis password secret" >&2
    exit 1
fi

REDIS_PASSWORD="$(cat "$REDIS_PASSWORD_FILE")"

if [ -z "$REDIS_PASSWORD" ]; then
    echo "Redis password secret must not be empty" >&2
    exit 1
fi

exec redis-server \
    --bind 0.0.0.0 \
    --port 6379 \
    --protected-mode yes \
    --requirepass "$REDIS_PASSWORD" \
    --save "" \
    --appendonly no \
    --daemonize no