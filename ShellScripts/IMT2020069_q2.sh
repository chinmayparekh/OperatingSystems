# Program number 2
# Chinmay Parekh - IMT2020069
# Date - 21-1-2022
# Write a shell program that checks the number of command line arguments and echoes an error message
#  if there are not exactly three arguments or echoes the arguments themselves if there are three.  
#!/bin/bash
if [[ $# -eq 3 ]]
then
  echo $@
else
    echo "Error"
fi