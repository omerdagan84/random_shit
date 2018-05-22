#!/bin/bash

#create IP directories
PWD=$(pwd)
cat proxy_iplist | while read ip 
do
	mkdir -p $PWD/P_$ip
done
cat cont_iplist | while read ip 
do
	mkdir -p $PWD/C_$ip
done

#copy log files from devices
while true; do
	cat proxy_iplist | while read ip 
	do
		echo $ip
		sshpass -p "p@ssw0rdRisco" scp -o StrictHostKeyChecking=no -r root@$ip:/DATA/log/messages.0 $PWD/P_$ip/messages_$(date +"%H_%M__%d_%m")
	done
	cat cont_iplist | while read ip 
	do
		echo $ip
		sshpass -p "qazxsw" scp -o StrictHostKeyChecking=no -r root@$ip:/DATA/log/messages.0 $PWD/C_$ip/messages_$(date +"%H_%M__%d_%m")
	done
sleep 120 
done

