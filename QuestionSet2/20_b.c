//  Program number 20
//  Chinmay Parekh - IMT2020069
//  Date - 22-04-2022
// Write two programs so that both can communicate by FIFO -Use one way communication.

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv []){
    int fd = open("myfifo",O_WRONLY);
    char msg[100] = "hello! How are you?\n" ;
    write(fd,msg,100);
    return 0;
}