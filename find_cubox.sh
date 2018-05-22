#!/bin/bash

echo "123456" | sudo -S arp-scan -l | grep -m1 -i --line-buffered  "d0:63:b4:01:14:e4" | awk '{print $1}'

