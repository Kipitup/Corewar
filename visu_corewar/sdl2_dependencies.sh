#!/bin/bash

usage ()
{
	printf "Usage ./sld2_dependencies [-linux | -macos]\n"
	printf "You must specify your operating system.\n"
	exit
}
if [ -n "$1" ]
then
	if [[ $1 == --help ]]
	then
		usage
		exit	
	fi
	if [[ $1 == -linux ]]
	then
		sudo apt-get install libsdl2-2.0-0 libsdl2-dev libsdl2-ttf-2.0-0 libsdl2-ttf-dev libsdl2-image-2.0-0 libsdl2-image-dev
		exit	
	fi
	if [[ $1 == -macos ]]
	then
		brew install libsdl2-2.0-0 libsdl2-dev libsdl2-ttf-2.0-0 libsdl2-ttf-dev libsdl2-image-2.0-0 libsdl2-image-dev
		exit
	fi
else
	usage
	exit
fi
