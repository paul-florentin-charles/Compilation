#!/bin/bash

RESET="\033[0;0m"
RED=${RESET}"\033[1;31m"
BLUE=${RESET}"\033[1;34m"
YELLOW=${RESET}"\033[1;33m"
GREEN=${RESET}"\033[1;32m"
BOLD=${RESET}"\033[1m"

usage() {
    echo "Usage :"
    echo -e "bash run_tests.sh [-v] [-f FILE]\n\n The ${BOLD}-v${RESET} options prints test results in a convenient way\n The ${BOLD}-f${RESET} options specifies a specific test file. For example:\n   bash run_tests.sh -f ./resultat/test1\n will test compilation of ./resultat/test1.c\n If no file is provided, will launch all tests in ./test and ./resultat\n It is possible to give several files with several ${BOLD}-f${RESET} options"
}

while [ $# -ne 0 ]
do
    arg=$1
    shift
    case "$arg" in
	"-v")
	    VERBOSE=1
	    ;;
	"-f")
	    if [ $# -eq 0 ];
	    then
		echo -e "No file specified after ${BOLD}-f${RESET} option"
		usage
		exit 1
	    fi
	    FILES="${FILES} $1"
	    shift
	    ;;
	*)
	    echo -e "Unknown option : ${BOLD}$arg${RESET}"
	    usage
	    exit 1
	    ;;
    esac
done

tests() {
    for tst in $(ls $1/*.c)
    do
	t=${tst::-2}
        test $t
    done    
}

test() {
    t=$1
    if [ ! -f $t.c ];
    then
	echo -e "${BLUE}Test \"$t\" not found, skipping${RESET}"
	return 1
    fi
    
    ((./bin/lcc < $t.c) > $t.ll) 2> $t.txt
    if [ "${VERBOSE}" == "1" ];
    then
	echo -en "${YELLOW}"
	echo $t
	echo -en "${RESET}"	
	pr -m -t $t.c $t.ll
	echo -en "${RED}"
	cat $t.txt
	echo -e "${RESET}"
    fi
}

make

echo ""
echo -e "${GREEN}### Compilation tests ###${RESET}"

if [ "$FILES" == "" ];
then
    # Tests des enseignants
    tests ./resultat
    
    # Nos tests
    tests ./test
else
    for tst in ${FILES}
    do
	test $tst
    done
    
fi

