#!/bin/bash
# Переключает на источник Media Player
IP="192.168.1.12"

{
echo "SIMPLAY"
sleep 1
} | nc -w 2 "$IP" 23

echo "Источник переключен на Media Player"
