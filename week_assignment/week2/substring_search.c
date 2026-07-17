#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_substring(char *haystack,const char *needle){
    int i=0;
    int j=0;
    while(haystack[i]!='\0'){
        if(haystack[i]==needle[j]){
            int p=i;
            while(haystack[p]!='\0'){
                if(needle[j]==haystack[p]){
                    p++;
                    j++;
                }
                else{
                    break;
                }
            }
            if(needle[j]=='\0'){
                return i;
            }
        }
        i++;
    }
    return -1;
}

int main(int argc,char *argv[]){
    if(argc<2){
        printf("enter valid params");
        return 1;
    }
    char *haystack=argv[1];
    char *needle=argv[2];
    int index=find_substring(haystack,needle);
    printf("the first index of matched substring %d\n",index);

}