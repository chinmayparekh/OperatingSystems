# Program number 8
# Chinmay Parekh - IMT2020069
# Date - 21-1-2022
# Write shell script that takes a login name as command – line argument and reports when that person logged in. 

#!/bin/bash

read -p 'Enter username to check: ' user
if who -u | grep -q "^$user "; then
    # top -u "$user"
    echo "User $user is logged in"
else
    echo "User $user is not logged in"
fi