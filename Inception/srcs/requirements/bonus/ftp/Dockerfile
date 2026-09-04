FROM debian:bookworm

RUN apt-get update && apt-get install -y --no-install-recommends \
        vsftpd \
    && rm -rf /var/lib/apt/lists/*

COPY conf/vsftpd.conf.template /etc/vsftpd.conf.template
COPY tools/entrypoint.sh /usr/local/bin/entrypoint.sh

RUN chmod +x /usr/local/bin/entrypoint.sh

EXPOSE 21 21000-21010

ENTRYPOINT ["/usr/local/bin/entrypoint.sh"]
