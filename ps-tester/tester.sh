#!/bin/bash

# This script is used to test the program push_swap

# Variables
files=()
norm_error=0
loop_size=10
100_rnd_inst=0

# Options
no_norm=0
no_make=0
no_test=0
debug=0

# Arguments
while getopts "dnmt" opt; do
	case $opt in
		d)
			debug=1
			set +x
			;;
		n)
			no_norm=1
			;;
		m)
			no_make=1
			;;
		t)
			no_test=1
			;;
	esac
done

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YEllOW='\033[1;33m'
NC='\033[0m'

# Functions
function randint()
{
	min=$1
	max=$2
	echo $((min + RANDOM % (max - min + 1)))
}
if [ $no_norm -eq 1 ]
then
	echo -e "$YEllOW""Norminette is ignored $NC"
else
	files=($(find "$(pwd)" -type f \( -name "*.c" -o -name "*.h" \)))

	for file in ${files[@]}
	do
		norn_output=$(norminette $file)
		if [ "$norn_output" != "$file: OK!" ]
		then
			norminette $file
			((norm_error++))
		fi
	done

	if [ $norm_error -eq 0 ]
	then
		echo -e "$GREEN Norminette OK! $NC"
	else
		echo -e "$RED File with Norm error : $norm_error $NC"
	fi
fi

# Compile the program
if [ $no_make -eq 1 ]
then
	echo -e "$YEllOW""Make is ignored $NC"
else
	make re
	(cd ../ && make re)
fi

if [ $no_test -eq 1 ]
then
	echo -e "$YEllOW""Test is ignored $NC"
else
	echo "$YEllOW 100 random numbers $NC"
	for i in $(seq 1 $loop_size)
	do
		min=$(randint "-1000" "1000")
		max=$(randint "-1000" "1000")
		ARG=$(seq $min $max | sort -R | tr '\n' ' ')
		push_output=$(../push_swap $ARG)
		((100_rnd_inst+=($push_output | wc -l)))
		if [ $(tail $push_output) == "KO" ]
		then
			echo -e "$RED""KO $NC"
		else
			echo -e "$GREEN""OK $NC"
		fi
		echo
	done
	echo -e "$GREEN""100 random numbers OK! $NC"
fi