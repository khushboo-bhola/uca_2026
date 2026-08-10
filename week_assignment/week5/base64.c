#include <stdio.h>
#include <string.h>

const char table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

int findValue(char ch) {
    for(int i=0;i<64;i++) {
        if(table[i] == ch)
            return i;
    }
    return -1;
}

void encodeText() {
    char input[1000];

    printf("Enter Normal String : ");
    getchar();
    fgets(input,1000,stdin);

    input[strcspn(input,"\n")] = '\0';

    int n = strlen(input);
    printf("\nEncoded String : ");

    for(int i=0;i<n;i+=3) {
        unsigned char a = input[i];
        unsigned char b = (i+1<n) ? input[i+1] : 0;
        unsigned char c = (i+2<n) ? input[i+2] : 0;

        unsigned int value = (a<<16) | (b<<8) | c;

        char x = table[(value>>18)&63];
        char y = table[(value>>12)&63];
        char z = table[(value>>6)&63];
        char w = table[value&63];

        if(i+1>=n) {
            z='=';
            w='=';
        }
        else if(i+2>=n) {
            w='=';
        }

        printf("%c%c%c%c",x,y,z,w);
    }

    printf("\n");
}

void decodeText() {
    char input[1000];

    printf("Enter Base64 String : ");
    scanf("%999s",input);

    int n = strlen(input);
    printf("\nDecoded String : ");

    for(int i=0;i<n;i+=4) {
        int a = findValue(input[i]);
        int b = findValue(input[i+1]);
        int c = (input[i+2]=='=') ? 0 : findValue(input[i+2]);
        int d = (input[i+3]=='=') ? 0 : findValue(input[i+3]);

        unsigned int value = (a<<18) | (b<<12) | (c<<6) | d;

        char x = (value>>16)&255;
        char y = (value>>8)&255;
        char z = value&255;

        printf("%c",x);

        if(input[i+2]!='=')
            printf("%c",y);

        if(input[i+3]!='=')
            printf("%c",z);
    }

    printf("\n");
}

int main() {
    int choice;

    printf("BASE64 Encoding/Decoding\n");
    printf("1. Encode\n");
    printf("2. Decode\n");
    printf("Enter choice: ");

    scanf("%d",&choice);

    if(choice==1)
        encodeText();
    else if(choice==2)
        decodeText();
    else
        printf("Invalid Choice\n");

    return 0;
}