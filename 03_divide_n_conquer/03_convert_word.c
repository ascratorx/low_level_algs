#include <stdio.h>
#include <stdint.h>

// Gibt nur die niederwertigste 1 im Bitmuster zurück (rekursiv, divide & conquer)
uint64_t isolate_lowest_one(uint64_t value, int bits, int shift) {
    if (bits == 0) return 0; // nichts gesetzt
    //show_bits(value);
    if ((value >> shift) & 0x1) {
        return (uint64_t)1 << shift; // Treffer: erste gesetzte 1 von rechts
    }

    int half = bits / 2;
    uint64_t left = bits & 0xFFFFFFFF;
    uint64_t right = bits >> half;

    if (left) {
        return isolate_lowest_one(left, half, shift);
    } else {
        return isolate_lowest_one(right, half, shift + half);
    }
}

// Gibt eine 64-Bit-Zahl als Binärfolge aus
void show_bits(uint64_t x) {
    for (int i = 63; i >= 0; i--) {
        printf("%c", (x & ((uint64_t)1 << i)) ? '1' : '0');
    }
    printf("\n");
}

int main() {
    uint64_t input = 0b1011001100000000ULL;

    printf("Original : ");
    show_bits(input);

    uint64_t result = isolate_lowest_one(input, sizeof(input) * 8, 0);

    printf("Ergebnis : ");
    show_bits(result);

    return 0;
}
