#include <iostream>

int multiply(int a, int b) {
    int result = 0;

    // Handle negatives
    bool isNegative = false;
    if (a < 0) {
        a = -a;
        isNegative = !isNegative;
    }
    if (b < 0) {
        b = -b;
        isNegative = !isNegative;
    }

    while (b > 0) {
        // Wenn b gerade ist, einfach a addieren
        if (b & 1) {
            result += a;
        }

        // A verdoppeln und B halbieren
        a <<= 1;  // a = a * 2
        b >>= 1;  // b = b / 2
    }

    return isNegative ? -result : result;
}

int main() {
    int x, y;
    std::cout << "Geben Sie die erste Zahl ein: ";
    std::cin >> x;
    std::cout << "Geben Sie die zweite Zahl ein: ";
    std::cin >> y;

    int produkt = multiply(x, y);
    std::cout << "Das Produkt ist: " << produkt << std::endl;

    return 0;
}
