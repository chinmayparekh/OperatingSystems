# Program number 14
# Chinmay Parekh - IMT2020069
# Date - 21-1-2022
# Write a shell script to print, “Good Morning/Afternoon/Evening based on the current system time. 

#!/bin/bash
ans="`date +%H`"
echo $ans
if [ $ans -lt 12 ]
then
   echo "Good Morning"
elif [ $a -lt 16 ]
then
   echo "Good Afternoon"
else
   echo "Good Evening"
fi