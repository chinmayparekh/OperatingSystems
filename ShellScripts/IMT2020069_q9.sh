# Program number 9
# Chinmay Parekh - IMT2020069
# Date - 21-1-2022
# Write a shell script that accepts a file name starting and ending line numbers as arguments and displays all the lines between the given line numbers. 

#!/bin/bash
echo "Enter a file name"  
read file_name
echo "Enter the starting line"
read starting
echo "Enter the ending line"
read ending
# tail -n +$((starting+1)) $file_name | head -n $((ending - starting -1))
sed -n "$((starting+1))","$((ending-1))"\p $file_name