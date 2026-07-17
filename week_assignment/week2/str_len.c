#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[]){
    if(argc<2){
        printf("Enter a string");
        
    }
    char *str=argv[1];
    int len=0;
    for(int i=0;str[i]!='\0';i++){
        len++;
    }
    printf("The len of String is %d\n",len);
}