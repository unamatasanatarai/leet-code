FROM alpine:latest

# Install basic packages and languages
RUN apk add --no-cache \
    python3 \
    py3-pip \
    go \
    php \
    php-openssl \
    php-phar \
    php-mbstring \
    php-tokenizer \
    rust \
    cargo \
    nodejs \
    npm \
    build-base \
    vim \
    curl \
    git \
    bash \
    prettier \
    rustfmt

# Install uv (astral)
RUN pip3 install uv --break-system-packages

# Install Composer
RUN curl -sS https://getcomposer.org/installer | php && \
    mv composer.phar /usr/local/bin/composer && \
    chmod +x /usr/local/bin/composer

# Install php-cs-fixer globally
RUN curl -L https://cs.symfony.com/download/php-cs-fixer-v3.phar -o /usr/local/bin/php-cs-fixer && \
chmod +x /usr/local/bin/php-cs-fixer


WORKDIR /root/dev
