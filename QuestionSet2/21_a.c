//  Program number 21
//  Chinmay Parekh - IMT2020069
//  Date - 22-04-2022
// Write two programs so that both can communicate by FIFO -Use two way communications.
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv []){
    int fd1 = open("myfifo1",O_RDWR);
    int fd2 = open("myfifo2",O_RDWR);
    const int msg_size = 1000;
    char msg_read[msg_size] ;
    char msg_write[msg_size];

    int size = read(fd1,msg_read,msg_size);
    printf("%s\n",msg_read);
    printf("enter message : ");
    scanf("%s",msg_write);
    write(fd2,msg_write,msg_size);
    
    return 0;
}
