# Program number 10
# Chinmay Parekh - IMT2020069
# Date - 21-1-2022
# Write a script to backup a given directory to a given file name  in your home directory. 
# Both, the directory name and the backup file has to be passed as  command line input. 
# Design the script with suitable exception handling.
#! /bin/bash
echo Enter the backup filename with tar.gz extension
read backup
echo give the existing directory path.
read path
ans=`tar -zcvf $backup $path`
echo directory $path successfully backed up $ans