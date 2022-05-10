# Program number 1
# Chinmay Parekh - IMT2020069
# Date - 21-1-2022
# Write a shell script to count the number of block device files in /dev directory. 


#!/bin/sh

ans=$(ls -Rl /dev/ |grep ^b | wc -l)
echo "$ans"
