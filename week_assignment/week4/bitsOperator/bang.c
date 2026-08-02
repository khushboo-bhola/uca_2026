#include <stdio.h>

int bang(int x) {
    int negative = ~x + 1;
    int sign = (x | negative) >> 31;

    return sign + 1;
}

int main() {
    int x;

    printf("Enter number: ");
    scanf("%d", &x);

    printf("Result = %d\n", bang(x));

    return 0;
}