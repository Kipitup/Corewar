#!/bin/bash


# '-n' : true if the lenght of the string is nonzero
if [ -n "$1" ]
then
	file_1=$1
elif [ -n "$2" ]
then
	file_2=$2
elif [ -n "$3" ]
then
	file_3=$3
elif [ -n "$4" ]
then
	file_4=$4
fi

print_line () #
{
	printf "\n________________________________________________\n"
}

./corewar -dump 2000 -n 3 $file_1 -n 2 $file_2 $file_3
print_line

./corewar -n 5 $file_1
print_line

./corewar $file_1 -dump 2000
print_line

./corewar -n 3 $file_1 $file_2
print_line

./corewar -dump -5 $file_1 $file_2
print_line

./corewar -dump $file_1 $file_2
print_line

./corewar $file_1 $file_2
print_line

./corewar -n 2 $file_2 batman.s
print_line

./corewar $file_2 batman.cor
print_line

./corewar $file_1 $file_2 $file_3 $file_4 batman.cor
print_line

./corewar -dump 2000 -dump 500 $file_2 $file_3
print_line

