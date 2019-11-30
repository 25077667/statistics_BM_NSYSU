#!/bin/bash

for cpps in "$search_dir"./*.cpp
do 
    echo "compiling ${cpps:2}"
    g++ $cpps -o ${cpps:2:4}elf
done