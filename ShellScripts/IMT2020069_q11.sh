# Program number 11
# Chinmay Parekh - IMT2020069
# Date - 21-1-2022
# Write a script to check how much space is used by each directory of a given file system. 
# The name of the file system has to be provided from the command  line parameter.

#!/bin/sh
echo "Enter file to be checked "  
read file_name
du -h $file_name
