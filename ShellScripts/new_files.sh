# Program number 3
# Chinmay Parekh - IMT2020069
# Date - 21-1-2022
# Write a shell program called new_files that will accept a variable number of command line arguments. 
# The shell program will create a new file associated with each command line argument and echo a message that notifies the user as each file is created. 

#!/bin/bash 
for i; do 
   touch $i 
   echo file $i is created
done