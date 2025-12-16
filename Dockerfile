FROM alpine:latest

# Install basic packages and languages
RUN apk add --no-cache \
    python3 \
    py3-pip \
    go \
    php \
    rust \
    cargo \
    nodejs \
    npm \
    build-base \
    vim \
    curl \
    git \
    bash \
    rustfmt

# Install uv (astral)
RUN pip3 install uv --break-system-packages

WORKDIR /home/dev
