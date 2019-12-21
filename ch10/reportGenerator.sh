#!/bin/bash

echo "B073040047 report" >report.txt

for elfs in "$search_dir"./*.elf; do
    echo ${elfs:2}
    $elfs &>>report.txt
    echo >>report.txt
done

echo "B073040047 report" >>report.txt
