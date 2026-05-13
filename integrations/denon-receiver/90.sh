#!/bin/bash
# Включает ресивер через Telnet
IP="192.168.1.12"

{
echo "PWON"
sleep 1
} | nc -w 2 "$IP" 23

echo "Команда PWON отправлена через Telnet"
