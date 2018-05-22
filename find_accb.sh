#!/bin/bash

echo "123456" | sudo -S arp-scan -l | grep -m1 -i --line-buffered  "$1" | awk '{print $1}'

