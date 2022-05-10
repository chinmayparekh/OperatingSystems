#!/bin/sh

echo "Enter the file whose soft link has to be created"
read file_name
echo "Enter the name of the soft link"
read soft_link

ln -s $file_name $soft_link

