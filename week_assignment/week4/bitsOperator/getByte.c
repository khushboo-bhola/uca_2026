#include <stdio.h>

int getByte(int x, int n) {
    int shift = n << 3;
    return (x >> shift) & 0xFF;
}

int main() {
    int x = 0x12345678;
    int n = 1;

    printf("Byte = 0x%x\n", getByte(x, n));

    return 0;
}
