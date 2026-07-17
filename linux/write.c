#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main(int argc, char *argv[]){
    if(argc<2){
        printf("enter the file name");
        return 1;
    }
    int fd=open(argv[1],O_RDONLY);
    char buffer[7];
    ssize_t bytesRead;
    while((bytesRead=read(fd,buffer,sizeof(buffer)))>0){
        write(STDOUT_FILENO,buffer,bytesRead);
       
    }
    close(fd);
    return 0;
}
