# Program number 15
# Chinmay Parekh - IMT2020069
# Date - 21-1-2022

# SED - Write a shell script to perform the following (input file “example” will be given).
# For a given file, find all the lines containing our search pattern.
# List the lines not containing the search string
# Matching lines starting with a given pattern and ending in a second pattern
# Print a file starting from a certain line until to the end of file.
# Search a given pattern in a file and replace with a new pattern and display the file.
# Insert a given string at the beginning of each line of the file.
# Insert a given string at the end of each line of the file

#!/bin/bash

echo enter your choice 1/2/3/4/5/6/7:
read choice

case $choice in 

        1) 
            echo Enter search pattern 
            read search_pattern
            sed -n '/'"$search_pattern"'/p' employee.txt;;
        2) 
            echo Enter search string 
            read search_string
            sed '/'"$search_string"'/d' employee.txt;;        
            
        3)  echo Enter pattern 1
            read pattern1
            echo Enter your pattern 2
            read pattern2
            sed -n "/^$pattern1.*$pattern2.$/p" employee.txt;;

        4) echo Enter start line number
           read number
           tail -n +$number employee.txt;;

        5) echo Enter the text to be replaced 
           read text
           echo Enter new text 
           read new_text
           sed s'/'"$text/$new_text"'/' employee.txt;;

        6) echo enter a string to display at the start of each line
           read string
           sed s'/'"^/$string"'/' employee.txt;;

        7) echo enter a string to display at the end of each line
           read string
           sed s'/'"$/$string "'/' employee.txt;;

esac