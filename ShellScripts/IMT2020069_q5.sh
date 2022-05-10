# Program number 5
# Chinmay Parekh - IMT2020069
# Date - 21-1-2022
# Write a script that uses find to look for a file and echo a suitable message if the file is not found. You must not store the output of the find to a file.

#!/bin/sh
echo "Enter file to be searched "  
read FILE
ans=`find / -name $FILE 2>/dev/null | wc -l`
if [ $ans = 0 ] 
 then
        echo "The file doesnt exist"
else
        echo "The file exists"
fi