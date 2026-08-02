#include <stdio.h>

int bitXor(int x, int y) {
    int first = x & ~y;
    int second = ~x & y;

    return ~(~first & ~second);
}

int main() {
    int x, y;

    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);

    printf("XOR = %d\n", bitXor(x, y));

    return 0;
}