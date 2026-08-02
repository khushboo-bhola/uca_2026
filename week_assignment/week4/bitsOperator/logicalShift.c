#include <stdio.h>

int logicalShift(int x, int n) {
    int shifted = x >> n;
    int mask = ~(((1 << 31) >> n) << 1);
    return shifted & mask;
}

int main() {
    int x = 0x87654321;
    int n = 4;

    printf("Result = 0x%x\n", logicalShift(x, n));

    return 0;
}