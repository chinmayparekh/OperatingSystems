#!/bin/sh

echo "Enter the file whose hard link has to be created"
read file_name
echo "Enter the name of the hard link"
read hard_link

ln $file_name $hard_link


