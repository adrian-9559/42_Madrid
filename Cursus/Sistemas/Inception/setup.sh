#!/bin/bash
set -euo pipefail

USER_NAME="$(id -un)"
DOMAIN="${USER_NAME}.42.fr"
PROJECT_DIR="$(cd "$(dirname "$0")" && pwd)"
ENV_FILE="$PROJECT_DIR/srcs/.env"

mkdir -p "$PROJECT_DIR" >/dev/null

echo "=== Inception Setup ==="
echo "Usuario detectado: $USER_NAME"
echo "Dominio: $DOMAIN"

if [ ! -f "$ENV_FILE" ]; then
    cat > "$ENV_FILE" <<EOF
DOMAIN_NAME=$DOMAIN
MYSQL_DATABASE=wordpress
MYSQL_USER=${USER_NAME}_wp
MYSQL_PASSWORD=$(openssl rand -hex 16)
MYSQL_ROOT_PASSWORD=$(openssl rand -hex 16)

WP_TITLE=Inception
WP_ADMIN_USER=${USER_NAME}_admin
WP_ADMIN_PASSWORD=$(openssl rand -hex 16)
WP_ADMIN_EMAIL=${USER_NAME}@42.fr
WP_USER=${USER_NAME}_user
WP_USER_PASSWORD=$(openssl rand -hex 16)
WP_USER_EMAIL=${USER_NAME}.user@42.fr
EOF
    echo "Archivo de entorno generado en $ENV_FILE"
else
    echo "Se reutiliza el archivo existente $ENV_FILE"
fi

if ! grep -q "$DOMAIN" /etc/hosts 2>/dev/null; then
    if command -v sudo >/dev/null 2>&1; then
        echo "127.0.0.1 $DOMAIN" | sudo tee -a /etc/hosts >/dev/null
    else
        echo "127.0.0.1 $DOMAIN" >> /etc/hosts
    fi
    echo "Dominio $DOMAIN añadido a /etc/hosts"
else
    echo "Dominio $DOMAIN ya existe en /etc/hosts"
fi

make up

echo ""
echo "=== Setup completado ==="
echo "Accede a: https://$DOMAIN"
