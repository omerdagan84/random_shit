echo_red() {
    tput setaf 1
    echo "$@"
    tput sgr0
}

echo_green() {
    tput setaf 2
    echo "$@"
    tput sgr0
}

echo_yellow() {
    tput setaf 3
    echo "$@"
    tput sgr0
}

echo_blue() {
    tput setaf 4
    echo "$@"
    tput sgr0
}

ret_check() {
	if [ $? -ne 0 ]; then
		tput setaf 1
		echo "$@"
		tput sgr0
		exit -1;
	fi
}

build_deps_check() {
    local res=1
    deps=( python git readlink mktemp )

    echo_blue "Checking dependencies for build"

    for var in "${deps[@]}"
    do
        echo -n "Checking for ${var}..."
        if [[ `which ${var}` == "" ]]; then
            echo_red " missing"
            res=0
        else
            echo_green " found"
        fi
    done

    if [[ res -eq 1 ]]; then
        echo_green "Looks like all prerequisites are there..."
    else
        ret_check "Error: build required components are missing!"
    fi
}

help_message() {}

while getopts ":ho::s:" key; do
case $key in
  h)
    help_message
    exit 0
    ;;

  c)
    conf_path=$(readlink -f "$OPTARG")
    ;;

  o)
    output_dir=$(readlink -f "$OPTARG")
    ;;

  s)
    SDK_ROOT=$(readlink -f "$OPTARG")
    ;;

  \?)
    echo "Invalid option: -$OPTARG" >&2
    exit 1
    ;;
  :)
    echo "Option -$OPTARG requires an argument." >&2
    exit 1
    ;;
esac
done

if [ $OPTIND -eq 1 ]; then
    help_message
    exit 0
fi

build_deps_check
grep -rl 'apples' /dir_to_search_under | xargs sed -i 's/apples/oranges/g'

