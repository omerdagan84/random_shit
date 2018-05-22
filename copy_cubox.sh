#!/bin/bash
function valid_ip()
{
	local  ip=$1
	local  stat=1

	if [[ $ip =~ ^[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}$ ]]; then
		OIFS=$IFS
		IFS='.'
		ip=($ip)
		IFS=$OIFS
		[[ ${ip[0]} -le 255 && ${ip[1]} -le 255 \
			&& ${ip[2]} -le 255 && ${ip[3]} -le 255 ]]
		stat=$?
	fi
	return $stat
}

if [ -z $1 ]; then 
	IP=172.16.19.13
else
	IP=$1
fi
if valid_ip $IP; then 
	echo "copying files to $IP:/tmp"
else
	echo "entered IP is invalid"
fi

sshpass -p 'r1sc0' scp libusb-1.0.so root@$IP:/tmp
sshpass -p 'r1sc0' scp uzbprog root@$IP:/tmp
sshpass -p 'r1sc0' scp run.sh root@$IP:/tmp
