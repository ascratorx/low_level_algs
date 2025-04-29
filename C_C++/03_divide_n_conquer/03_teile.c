#include <stdio.h>
#include <stdint.h>

// Aufgabe: Suche Algorithmus, der nur die niederwertigste 1 beibehält, Rest auf 0

uint64_t divide_and_conquer(uint64_t bits, int size, int shift) {
    if (bits == 0) return 0; // kein gesetztes Bit vorhanden

    if ((bits >> shift) & 0x1) {
        return (uint64_t)1 << shift; // niederwertigste 1 gefunden
    }

    uint32_t lower = (uint32_t)(bits & 0xFFFFFFFF);
    uint32_t upper = (uint32_t)(bits >> (size / 2));

    if (lower) {
        return divide_and_conquer(lower, size / 2, shift + 1);
    } else {
        return divide_and_conquer(upper, size / 2, shift + size / 2);
    }
}

// Gibt ein 64-Bit-Wort als Binärstring aus
void print_bits(uint64_t value) {
    for (int i = 63; i >= 0; i--) {
        printf("%c", (value & ((uint64_t)1 << i)) ? '1' : '0');
    }
    printf("\n");
}

int main() {
    // Beispielwert mit mehreren gesetzten Bits
    uint64_t bits = 0b1011001101011101000110111110001001101001101011000011110011000000ULL;

    volatile uint64_t result = divide_and_conquer(bits, sizeof(bits) * 8, 0);

    printf("Eingabe : ");
    print_bits(bits);

    printf("Ergebnis: ");
    print_bits(result);

    return 0;
}
