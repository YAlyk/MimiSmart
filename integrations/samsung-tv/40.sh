#!/bin/bash

# IP-адрес телевизора и ваш PSK-ключ
TV_IP="192.168.1.89"
PSK="1111"  # Замените на ваш ключ

echo "Выключение телевизора..."

curl -X POST \
  -H "Content-Type: application/json; charset=UTF-8" \
  -H "X-Auth-PSK: $PSK" \
  -d '{"method": "setPowerStatus", "params": [{"status": false}], "id": 1, "version": "1.0"}' \
  http://$TV_IP/sony/system

echo -e "\nГотово."
