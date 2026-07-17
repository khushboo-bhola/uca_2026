#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse_string(char *str){
    int start=0;
    int l=strlen(str);
    int end=l-1;
    while(start<end){
        char temp=str[start];
        str[start]=str[end];
        str[end]=temp;
        start++;
        end--;
    }
}

int main(int argc,char *argv[]){
    char *s=argv[1];
    reverse_string(s);
    printf("%s\n",s);
}