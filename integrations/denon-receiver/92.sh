#!/bin/bash
# Переключает на источник TV
IP="192.168.1.12"

{
echo "SITV"
sleep 1
} | nc -w 2 "$IP" 23

echo "Источник переключен на TV"
