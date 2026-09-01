#!/bin/sh
set -eu

if [ -n "${DOMAIN_NAME:-}" ]; then
    envsubst '\$DOMAIN_NAME' < /etc/nginx/nginx.conf > /tmp/nginx.conf
    cp /tmp/nginx.conf /etc/nginx/nginx.conf
fi

# Check if config is valid
nginx -t

# Start nginx in foreground (PID 1 best practice)
exec nginx -g "daemon off;"
