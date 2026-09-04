FROM debian:bookworm

RUN apt-get update && apt-get install -y --no-install-recommends \
        nginx \
    && rm -rf /var/lib/apt/lists/* \
    && rm -f /etc/nginx/sites-enabled/default

COPY conf/nginx.conf /etc/nginx/nginx.conf
COPY site/ /var/www/static/

EXPOSE 8080

ENTRYPOINT ["nginx", "-g", "daemon off;"]
