#!/bin/bash

# IP-адрес телевизора и ваш PSK-ключ
TV_IP="192.168.1.89"
PSK="1111"  # Замените на ваш ключ

echo "Переключение на HDMI 3..."

curl -X POST \
  -H "Content-Type: application/json; charset=UTF-8" \
  -H "X-Auth-PSK: $PSK" \
  -d '{"method": "setPlayContent", "params": [{"uri": "extInput:hdmi?port=3"}], "id": 1, "version": "1.0"}' \
  http://$TV_IP/sony/avContent

echo -e "\nГотово."
