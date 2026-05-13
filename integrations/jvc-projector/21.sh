#!/bin/bash

data='\x06\x14\x00\x04\x00\x34\x11\x01\x00\x5E\xC2'
ip="192.168.1.4"
port="4661"

echo -n -e "$data" > /dev/tcp/$ip/$port
echo "Команда успешно отправлена на $ip:$port"
