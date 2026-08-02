#include <stdio.h>

int isPower2(int x) {
    int xMinusOne = x + (~0);
    int checkPower = !(x & xMinusOne);
    int positive = !(x >> 31);
    
    return !!x & checkPower & positive;
}

int main() {
    int x;

    printf("Enter number: ");
    scanf("%d", &x);

    printf("Result = %d\n", isPower2(x));

    return 0;
}