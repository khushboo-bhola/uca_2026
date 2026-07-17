#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(int argc,char *argv[]){
    if(argc<2){
        printf("enter a string first");
    }
    char *str=argv[1];
    char *token=strtok(str,",");
    while(token!=NULL){
        printf("%s\n",token);
        token=strtok(NULL,",");
    }
}
