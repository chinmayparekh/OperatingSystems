# Program number 12
# Chinmay Parekh - IMT2020069
# Date - 21-1-2022
# Write a script in /root/myscript.sh according to the following criteria:
# If you search for the IIT the output is NIT
# If you search for NIT the output is IIT
# If you search any other keyword or not give any input, the output is STDERR should be displayed.

#! /bin/bash

read choice
case $choice in
     IIT)
         echo "NIT"
         ;;
     NIT)
         echo "IIT"
         ;;
     *)
       echo "STDERR"
       ;;
esac
