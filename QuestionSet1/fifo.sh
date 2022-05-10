#!/bin/sh

echo "Enter the the name of the fifo file"
read file_name
mkfifo $file_name


