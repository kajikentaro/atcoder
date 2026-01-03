#!/bin/bash
set -e

mkdir -p /run/sshd

# ホスト鍵がなければ作る（初回のみでOK）
if [ ! -f /etc/ssh/ssh_host_ed25519_key ]; then
  ssh-keygen -A
fi

USER=aaa

# 強いランダムパスワード（base64 24 bytes ≒ 32文字程度）
PASS="$(openssl rand -base64 24)"

echo "${USER}:${PASS}" | chpasswd

# ログに出す（検証用）。本番では避けるか、Secrets で渡す。
echo "==== SSH password for ${USER} ===="
echo "${PASS}"
echo "================================="

exec /usr/sbin/sshd -D -e
