# Program number 6
# Chinmay Parekh - IMT2020069
# Date - 21-1-2022
# Write a script which will give 4 choices to the user 1. ls   2. pwd  3. who 4. exit and execute the command as per the users choice.

#!/bin/sh

echo "1. ls   2. pwd  3. who 4. exit: "  
read command_choice 

case $command_choice in
   1) ls
   ;;
   2) pwd
   ;;
   3) who
   ;;
   4) exit
   ;;
esac