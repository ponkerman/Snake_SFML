#!/bin/bash

#functions ================================================================================
display_styled_symbol() {
	tput setaf $1
	tput bold
	echo "$2  $3"
	tput sgr0
}

build() {
    echo
	display_styled_symbol 0 "↺" "building..."
	if [ -f "bin/Debug/snake.exe" ]; then
		rm bin/Debug/snake.exe
	fi
	$(  F:/compilers/minGW64_old/mingw64/bin/g++.exe \
		src/* \
    	-o bin/Debug/snake.exe \
    	-LF:/compilers/SFML_GCC7.3.0x64/SFML-2.5.1/lib \
    	-IF:/compilers/SFML_GCC7.3.0x64/SFML-2.5.1/include \
    	-lsfml-graphics-d \
		-lsfml-window-d \
    	-lsfml-system-d \
	    -lsfml-audio-d \
    	-lsfml-network-d)
	if [ -f "bin/Debug/snake.exe" ]; then
		build_success
	else
		build_fail
	fi
}

build_success() {
	echo
	display_styled_symbol 2 "✔" "build succeed!"
}

build_fail() {
	echo
	display_styled_symbol 1 "✘" "building failed!"
	echo
	tput sgr0
	exit 1
}

launch() {
    echo
	display_styled_symbol 0 "↺" "launching..."
	$(bin/Debug/snake.exe)
}

#main script ==============================================================================
if [ "$1" == "debug" ]; then
    display_styled_symbol 0 " " "type: DEBUG"
	build
elif [ "$1" == "launch" ]; then
	display_styled_symbol 0 " " "type: LAUNCH"
	launch
elif [ "$1" == "debugNlaunch" ]; then
	display_styled_symbol 0 " " "type: DEBUG AND LAUNCH"
	build
	launch
else
    display_styled_symbol 1 " " "error: wrong type"
    exit 1
fi

exit 0