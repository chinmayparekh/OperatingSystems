# Program number 13
# Chinmay Parekh - IMT2020069
# Date - 21-1-2022
# Write a shell script to print a multiplication table.

#!/bin/bash

echo "Enter a Number"
read n
i=1

while [ $i -le 10 ]
do
          echo " $n x $i = $(( n * i ))"
          i=$(( i + 1 ))
done
