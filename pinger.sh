#!/bin/bash -x 
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

function callup() {
	touch /tmp/comm_chk
	exit 1
}

function calldown() {
	rm -f /tmp/comm_chk
}

function callup_accb() {
	touch /tmp/comm_chk_accb
	exit 1
}

function calldown_accb() {
	rm -f /tmp/comm_chk_accb
}
declare -a arr=(
	"NTP_Server_IP_Address"
	"RSP_IP_OR_URL"
	"NAT_IP"
	"Additional_RSP_Gateway_IP_Address"
	"Active_Proxy_IP_Address"
)

for i in "${arr[@]}"
do
	IP2PING=`cat /DATA/COMMON/boardConfigAdvanced.cfg | grep "$i" | grep -oE  "([0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3})"`
	if [ ! -z $IP2PING ]; then
		ping -w 1 -c 2 $IP2PING > /dev/null && callup || calldown
	fi

	IP2PING=`cat /DATA/COMMON/boardConfig.cfg | grep "$i" | grep -oE  "([0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3})"`
	if [ ! -z $IP2PING ]; then
		ping -w 1 -c 2 $IP2PING > /dev/null && callup || calldown
	fi
done

if [ ! -f /tmp/accblist ]; then
	`readDB 23 > /tmp/accblist`
fi

ACCB_IP=`cat /tmp/accblist | awk '{print $2}'`
for j in $ACCB_IP 
do 
	if  valid_ip $j; then
		ping -w 1 -c 2 $j > /dev/null && callup; callup_accb || calldown; calldown_accb
	fi
done
