#include <stdint.h>
#include <stdio.h>

int nextWord(uint8_t word) {

    uint32_t newWord = word | (word >> 1);    // Markiere gesetzte Bits + direkten rechten Nachbarn
    uint32_t mask   = newWord + 1;       // Erzeuge das nächste Musterkonstrukt
    uint32_t leastBit          = mask & -mask;  // Finde das niedrigst gesetzte Bit
    uint32_t toggledPattern    = word ^ leastBit;          // Toggle an genau dieser Stelle im ursprünglichen Muster (also 0 zu 1 und 1 zu 0)
    uint32_t clearedLowerBits  = toggledPattern & ~(leastBit - 1);  // Setze alle niedrigeren Bits auf 0

    return (int)(clearedLowerBits & 0xFF);  // Nur untere 8 Bit behalten
}

void print_binary(uint8_t x) {
    for (int i = 7; i >= 0; i--) {
        printf("%c", (x & (1 << i)) ? '1' : '.');
    }
}

int main() {
    uint8_t x = 0;
    int index = 0;

    printf("Gültige Worte (keine benachbarten Einsen):\n\n");
    printf("%4d: ", index++);
    print_binary(x);
    printf("\n");
    int next = nextWord(x);
    x = (uint8_t)next;

    while (1) {
        if(x==0) break;
        printf("%4d: ", index++);
        print_binary(x);
        printf("\n");
        next = nextWord(x);
        x = (uint8_t)next;
    }

    return 0;
}