#!/bin/bash
# Переключает на источник Game
IP="192.168.1.12"

{
echo "SIGAME"
sleep 1
} | nc -w 2 "$IP" 23

echo "Источник переключен на Game"
