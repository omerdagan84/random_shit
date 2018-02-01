NORMAL="\\033[0;39m"         # Standard console grey
SUCCESS="\\033[1;32m"        # Success is green
WARNING="\\033[1;33m"        # Warnings are yellow
FAILURE="\\033[1;31m"        # Failures are red
INFO="\\033[1;36m"           # Information is light cyan
BRACKET="\\033[1;34m"        # Brackets are blue

 echo -n -e "${BRACKET}test"
 echo -n -e "${NORMAL}test"
 echo -n -e "${INFO}test"
 echo -n -e "${WARNING}test"

