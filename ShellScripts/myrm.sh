# Program number 4
# Chinmay Parekh - IMT2020069
# Date - 21-1-2022
# Create a directory called .recyclebin in your home directory. Write a shell program called myrm that will move all of the files you 
# delete into the .recyclebin directory, your wastebasket. 
# This is a useful tool which will allow restoration of files after they have been removed.  Remember, the UNIX system has no undelete capability. 


#!/bin/sh

for i; do 
    sudo mv $i /home/.recyclebin 

done
    

