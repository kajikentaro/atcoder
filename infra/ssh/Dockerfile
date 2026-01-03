FROM kajindowsxp/atcoder:1.0.0

RUN apt-get install -y openssh-server sudo
RUN mkdir -p /run/sshd

RUN useradd -m -s /bin/bash aaa && \
    echo "aaa ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers && \
    mkdir -p /run/sshd
RUN sed -i 's/#PermitRootLogin prohibit-password/PermitRootLogin no/' /etc/ssh/sshd_config

COPY entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh

EXPOSE 22
ENTRYPOINT ["/entrypoint.sh"]
