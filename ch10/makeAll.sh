#!/bin/bash

for cpps in "$search_dir"./*.cpp; do
    echo "compiling ${cpps:2}"
    outname=$(echo "${cpps:2}" | cut -f 1 -d '.').elf
    g++ $cpps -o $outname
done
