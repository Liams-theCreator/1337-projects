FROM debian:bookworm

ARG PORTAINER_VERSION=2.39.6
ARG PORTAINER_SHA256=dea18370b6f6815a2d06ba59edf6932eb40df4c6a808279e2415ba050c5d292a

RUN apt-get update && apt-get install -y --no-install-recommends \
        ca-certificates \
        curl \
        tar \
    && mkdir -p /opt/portainer /data \
    && curl -fsSL \
        -o /tmp/portainer.tar.gz \
        "https://github.com/portainer/portainer/releases/download/${PORTAINER_VERSION}/portainer-${PORTAINER_VERSION}-linux-amd64.tar.gz" \
    && echo "${PORTAINER_SHA256}  /tmp/portainer.tar.gz" | sha256sum -c - \
    && tar -xzf /tmp/portainer.tar.gz -C /opt/portainer --strip-components=1 \
    && rm -f /tmp/portainer.tar.gz \
    && rm -rf /var/lib/apt/lists/*

COPY tools/entrypoint.sh /usr/local/bin/entrypoint.sh

RUN chmod +x /usr/local/bin/entrypoint.sh

WORKDIR /opt/portainer

EXPOSE 9000

ENTRYPOINT ["/usr/local/bin/entrypoint.sh"]
