#!/bin/sh
set -eu

# Validate required environment variables
: "${DOMAIN_NAME:?DOMAIN_NAME is required}"

if [ -n "${DOMAIN_NAME:-}" ]; then
    envsubst '\$DOMAIN_NAME' < /etc/nginx/nginx.conf > /tmp/nginx.conf
    cp /tmp/nginx.conf /etc/nginx/nginx.conf
fi

nginx -t

exec nginx -g "daemon off;"
