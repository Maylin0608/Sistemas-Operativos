#!/bin/bash


read -p "Ingresa el tiempo en segundos para apagar la computadora: " TIEMPO

3
MINUTOS=$((TIEMPO / 60))


if [ "$MINUTOS" -lt 1 ]; then
  MINUTOS=1
fi

sudo shutdown -h +$MINUTOS
sudo shutdown -c

echo "La computadora se apagará en aproximadamente $TIEMPO segundos..."


sleep 10

sudo shutdown -c


echo "El timer de apagado ha sido cancelado."
