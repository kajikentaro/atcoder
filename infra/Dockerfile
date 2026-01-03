# Ubuntuの公式コンテナを軸に環境構築
FROM ubuntu:24.04

# インタラクティブモードにならないようにする
ARG DEBIAN_FRONTEND=noninteractive

# タイムゾーンを日本に設定
ENV TZ=Asia/Tokyo

# インフラを整備
RUN apt-get update
RUN apt-get install -y time tzdata tree git curl

# C++
RUN apt-get install -y gcc-12 g++-12
RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-12 30 && \
    update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-12 30

# Node.js
RUN apt-get install -y nodejs npm
RUN update-alternatives --install /usr/bin/node node /usr/bin/nodejs 30

# Python3, PyPy3
RUN apt-get install -y python3.12 python3-pip pypy3
RUN update-alternatives --install /usr/bin/python python /usr/bin/python3.12 30 && \
    update-alternatives --install /usr/bin/pip pip /usr/bin/pip3 30 && \
    update-alternatives --install /usr/bin/pypy pypy /usr/bin/pypy3 30

# AtCoderでも使えるPythonライブラリをインストール
RUN pip install --break-system-packages \
    numpy scipy scikit-learn numba networkx

# C++でAtCoder Library(ACL)を使えるようにする
RUN git clone --depth 1 https://github.com/atcoder/ac-library.git /lib/ac-library
ENV CPLUS_INCLUDE_PATH=/lib/ac-library

# Pythonでの競技プログラミング用データ構造をインストール
RUN pip install --break-system-packages \
    git+https://github.com/hinamimi/ac-library-python git+https://github.com/hinamimi/python-sortedcontainers

# コンテスト補助アプリケーションをインストール
RUN pip install --break-system-packages online-judge-tools

RUN npm install -g atcoder-cli

# AHC用のRustのinstall
# RUN curl https://sh.rustup.rs -sSf | sh -s -- -y
# ENV PATH $PATH:/home/root/.cargo/bin

# 多倍長整数をインストール
RUN apt-get install -y libboost-all-dev

# GDB をインストール
RUN apt-get install -y gdb

# 日本語対応
RUN apt-get install -y locales && \
    echo "ja_JP.UTF-8 UTF-8" >> /etc/locale.gen && \
    locale-gen
ENV LANG=ja_JP.UTF-8
ENV LANGUAGE=ja_JP:ja
ENV LC_ALL=ja_JP.UTF-8

# atcoder-cliの設定
RUN acc config default-template cpp
RUN acc config default-test-dirname-format test
COPY template.json /root/.config/atcoder-cli-nodejs/cpp/template.json
COPY ac_template.cpp /root/.config/atcoder-cli-nodejs/cpp/main.cpp
# run these commands before you start
# $ acc login
# $ oj login https://beta.atcoder.jp/

# acコマンドのインストール
COPY ac* /usr/local/bin/

CMD ["/bin/bash"]