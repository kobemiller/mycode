#!/bin/sh -e
dir=($(ls))
for ((i=0; i<${#dir[@]}; i++))
do
    echo "dir[$i]:  ${dir[$i]}"
done
echo "the length of dir is: ${#dir[@]}"
