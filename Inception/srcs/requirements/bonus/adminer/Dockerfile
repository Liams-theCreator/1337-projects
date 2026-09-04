FROM debian:bookworm

RUN apt-get update && apt-get install -y --no-install-recommends \
        php-fpm \
        php-mysql \
        curl \
        ca-certificates \
    && mkdir -p /var/www/adminer \
    && curl -fsSL \
        -o /var/www/adminer/index.php \
        https://github.com/vrana/adminer/releases/download/v4.8.1/adminer-4.8.1.php \
    && chown -R www-data:www-data /var/www/adminer \
    && rm -rf /var/lib/apt/lists/*

COPY conf/www.conf /etc/php/8.2/fpm/pool.d/www.conf
COPY tools/entrypoint.sh /usr/local/bin/entrypoint.sh

RUN chmod +x /usr/local/bin/entrypoint.sh

WORKDIR /var/www/adminer

EXPOSE 9001

ENTRYPOINT ["/usr/local/bin/entrypoint.sh"]
