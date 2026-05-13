#!/bin/bash
# Выключает ресивер через Telnet
IP="192.168.1.12"

{
sleep 1
echo "PWSTANDBY"
sleep 1
echo "exit"
} | nc "$IP" 23

echo "Команда PWSTANDBY отправлена через Telnet"
