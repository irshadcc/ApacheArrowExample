ARG VARIANT=debian-11
FROM mcr.microsoft.com/vscode/devcontainers/cpp:0-${VARIANT}

RUN apt-get update -y -q && \ 
    apt-get install -y -q --no-install-recommends \
      build-essential \
      cmake \
      libboost-filesystem-dev \
      libboost-regex-dev \
      gdbserver \
      libboost-system-dev \
      libbrotli-dev \
      libbz2-dev \
      libgflags-dev \
      liblz4-dev \
      libprotobuf-dev \
      libprotoc-dev \
      libre2-dev \
      libsnappy-dev \
      libthrift-dev \
      libutf8proc-dev \
      libzstd-dev \
      pkg-config \
      protobuf-compiler \
      rapidjson-dev \
      zlib1g-dev 
    # && apt-get clean \
    # && rm -rf /var/lib/apt/lists*