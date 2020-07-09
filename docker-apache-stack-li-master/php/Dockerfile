ARG PHP_VERSION=""
FROM php:${PHP_VERSION:+${PHP_VERSION}-}fpm-alpine
COPY www.conf /usr/local/etc/php-fpm.d/www.conf
