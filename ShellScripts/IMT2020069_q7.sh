# Program number 7
# Chinmay Parekh - IMT2020069
# Date - 21-1-2022
# Write an interactive file-handling shell program that offers the user choice of copying, removing, rename. Once the user has made a choice, 
# the program ask user for the necessary information, such as the file name, new name. 

#!/bin/sh

echo "1. copying   2. removing  3. renaming : "  
read command_choice 

case $command_choice in
   1) echo "Enter the file name and another file in the same directory where you want to copy it. "  
        read file_name
        read path_name
        cp $file_name $path_name
   ;;
   2) echo "Enter the file name to be removed "  
        read file_name
        rm $file_name
   ;;
   3) echo "Enter the file to be renamed"  
        read file_name
      echo "Enter the new name"
        read name
        mv $file_name $name
   ;;
esac