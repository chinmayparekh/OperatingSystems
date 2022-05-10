//  Program number 9
//  Chinmay Parekh - IMT2020069
//  Date - 21-2-2022
// Write a program to print the following information about a given file.
// a. inode
// b. number of hard links
// c. uid
// d. gid
// e. size
// f. block size
// g. number of blocks
// h. time of last access
// i. time of last modification
// j. time of last change
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysmacros.h>

int main()
{
    int fd, inode, links, uid, gid, size, block_size, number_of_blocks;
    struct stat file_stat;
    lstat("9.c", &file_stat);
    inode = file_stat.st_ino;
    links = file_stat.st_nlink;
    uid = file_stat.st_uid;
    gid = file_stat.st_gid;
    size = file_stat.st_size;
    block_size = file_stat.st_blksize;
    number_of_blocks = file_stat.st_blocks;

    printf("Inode = %d\n", inode);
    printf("links = %d\n", links);
    printf("uid = %d\n", uid);
    printf("gid = %d\n", gid);
    printf("size = %d\n", size);
    printf("block size = %d\n", block_size);
    printf("number of blocks = %d\n", number_of_blocks);
    printf("time of last access: %s", ctime(&file_stat.st_atime));
    printf("time of last modification: %s", ctime(&file_stat.st_mtime));
    printf("time of last change: %s", ctime(&file_stat.st_ctime));

    return 0;
}
// check man fstat