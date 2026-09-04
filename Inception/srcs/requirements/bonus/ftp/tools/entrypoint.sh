#!/bin/bash
set -euo pipefail

FTP_ROOT="/var/www/html"

read_secret() {
    local variable_name="$1"
    local file_variable="${variable_name}_FILE"
    local file_path="${!file_variable:-}"

    if [ -z "$file_path" ] || [ ! -r "$file_path" ]; then
        echo "Missing readable secret file for ${variable_name}" >&2
        exit 1
    fi

    printf -v "$variable_name" '%s' "$(cat "$file_path")"

    if [ -z "${!variable_name}" ]; then
        echo "Empty secret for ${variable_name}" >&2
        exit 1
    fi
}

: "${FTP_USER:?FTP_USER is required}"
: "${FTP_PASV_ADDRESS:?FTP_PASV_ADDRESS is required}"

if [[ ! "$FTP_USER" =~ ^[a-z_][a-z0-9_-]*$ ]]; then
    echo "FTP_USER must contain only lowercase letters, numbers, underscores, or hyphens" >&2
    exit 1
fi

if [[ ! "$FTP_PASV_ADDRESS" =~ ^[0-9]{1,3}(\.[0-9]{1,3}){3}$ ]]; then
    echo "FTP_PASV_ADDRESS must be an IPv4 address" >&2
    exit 1
fi

read_secret FTP_PASSWORD

if ! id "$FTP_USER" >/dev/null 2>&1; then
    useradd \
        --no-create-home \
        --home-dir "$FTP_ROOT" \
        --gid www-data \
        --shell /bin/bash \
        "$FTP_USER"
fi

echo "${FTP_USER}:${FTP_PASSWORD}" | chpasswd

mkdir -p "$FTP_ROOT"
mkdir -p /var/run/vsftpd/empty
chown root:root /var/run/vsftpd/empty
chmod 0555 /var/run/vsftpd/empty
chown -R www-data:www-data "$FTP_ROOT"
find "$FTP_ROOT" -type d -exec chmod g+rwx {} +
find "$FTP_ROOT" -type f -exec chmod g+rw {} +

sed "s|__FTP_PASV_ADDRESS__|${FTP_PASV_ADDRESS}|g" \
    /etc/vsftpd.conf.template > /etc/vsftpd.conf

exec /usr/sbin/vsftpd /etc/vsftpd.conf
