#include <stdio.h>

int bitAnd(int x, int y) {
    int notX = ~x;
    int notY = ~y;
    int result = ~(notX | notY);

    return result;
}

int main() {
    int x, y;

    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);

    int answer = bitAnd(x, y);

    printf("Bitwise AND = %d\n", answer);

    return 0;
}