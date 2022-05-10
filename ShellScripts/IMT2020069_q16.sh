# Program number 16
# Chinmay Parekh - IMT2020069
# Date - 21-1-2022

# AWK – Write a Shell script to (The input file “employee.txt” will be given)
# Display a given file.
# Print the lines which match with a given pattern.
# Print only a specific field in the file.
# Format a given file with Name, Designation, Department and Salary headings and at the end of a file print Report Generated.
# Find the employees, who has id > 200
# Find the list of employees in a Technology Department.
# Print the number of employees in Technology Department.

#!/bin/bash

echo enter your choice 8/9/10/11/12/13/14:
read choice

case $choice in 

        8) cat employee.txt;;

        9) 
            echo Enter your search pattern 
            read search_pattern
            awk '/'"$search_pattern"'/' employee.txt;;
        10)
            echo Enter the field number you want to display 
            read f_num
            awk '{''print'' $'"$f_num"'}' employee.txt;;
        11) awk 'BEGIN {print "Name\tDesignation\tDepartment\tSalary";}
           {print $2,"\t",$3,"\t",$4,"\t",$NF;} 
           END {print "Report Generated\n--------------";}' employee.txt ;;

        12) awk '$1 >200' employee.txt ;;

        13)awk '$4 ~/Technology/' employee.txt ;;

        14)awk 'BEGIN { count=0;} 
            $4 ~ /Technology/ { count++; } 
            END { print "Number of employees in Technology Dept =",count;}' employee.txt 
esac            