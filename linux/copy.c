#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
    if(argc<3){
        printf("enter the valid parameteers");
        return 1;
    }
    int fd1=open(argv[1],O_RDONLY);
    int fd2=open(argv[2],O_WRONLY|O_CREAT,0644);

    char buffer[7];
    ssize_t bytesRead;
    while((bytesRead=read(fd1,buffer,sizeof(buffer)))>0){
        write(fd2,buffer,bytesRead);
    }
    close(fd1);
    return 0;
}