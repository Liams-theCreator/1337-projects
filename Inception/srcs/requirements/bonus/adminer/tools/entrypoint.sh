#!/bin/bash
set -euo pipefail

if [ ! -r /var/www/adminer/index.php ]; then
    echo "Adminer application file is missing" >&2
    exit 1
fi

chown -R www-data:www-data /var/www/adminer

exec php-fpm8.2 -F
