#!/bin/bash

hcitool scan
echo

echo "Write MAC (XX:XX:XX:XX:XX:XX)"
read MAC

echo $MAC
sudo rfcomm bind rfcomm0 $MAC 1
echo

cd send
./send /dev/rfcomm0
