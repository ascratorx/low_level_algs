#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Erzeugt eine zufällige Binärzahl der Länge n als String
void generate_random_binary(char *word, int n) {
    for (int i = 0; i < n; i++) {
        word[i] = (rand() % 2) ? '1' : '0';
    }
    word[n] = '\0'; // String-Ende setzen
}

// Sucht rekursiv von rechts die erste '1' (also die niedrigstwertige)
int find_rightmost_one(char *word, int left, int right) {
    if (left == right) {
        return (word[left] == '1') ? left : -1;
    }

    int mid = left + (right - left) / 2;
    int right_half = find_rightmost_one(word, mid + 1, right);
    
    if (right_half != -1) return right_half;
    return find_rightmost_one(word, left, mid);
}

// Lässt nur die am weitesten rechts stehende 1 stehen – alle anderen werden zu 0
void keep_only_rightmost_one(char *word, int length) {
    int index = find_rightmost_one(word, 0, length - 1);

    for (int i = 0; i < length; i++) {
        word[i] = (i == index) ? '1' : '0';
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Verwendung: %s <Länge>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    if (n <= 0) {
        fprintf(stderr, "Die Länge muss eine positive Zahl sein.\n");
        return 1;
    }

    char word[n + 1];
    srand(time(NULL));

    generate_random_binary(word, n);
    printf("Original:   %s\n", word);

    keep_only_rightmost_one(word, n);
    printf("Bearbeitet: %s\n", word);

    return 0;
}
