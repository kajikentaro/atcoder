FROM kajindowsxp/atcoder:1.0.0

RUN apt-get install -y openssh-server sudo
RUN mkdir -p /run/sshd

RUN useradd -m -s /bin/bash aaa && \
    echo "aaa ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers && \
    mkdir -p /run/sshd
RUN sed -i 's/#PermitRootLogin prohibit-password/PermitRootLogin no/' /etc/ssh/sshd_config

COPY entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh

# Register environment variables again because sshd doesn't extend ENV on Dockerfile
RUN echo 'TZ="Asia/Tokyo"' >> /etc/environment && \
    echo 'CPLUS_INCLUDE_PATH="/lib/ac-library"' >> /etc/environment && \
    echo 'LANG="ja_JP.UTF-8"' >> /etc/environment && \
    echo 'LANGUAGE="ja_JP:ja"' >> /etc/environment && \
    echo 'LC_ALL="ja_JP.UTF-8"' >> /etc/environment

EXPOSE 22
ENTRYPOINT ["/entrypoint.sh"]
