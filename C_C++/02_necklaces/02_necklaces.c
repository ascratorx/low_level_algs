#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int are_rotationally_equivalent(int *a, int *b, int n) {
    for (int shift = 0; shift < n; shift++) {
        int match = 1;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[(i + shift) % n]) {
                match = 0;
                break;
            }
        }
        if (match) return 1;
    }
    return 0;
}

void generate_necklaces(int n, int k) {
    int *necklace = malloc(n * sizeof(int));
    int seen[10000][n];
    int seen_count = 0;

    for (int i = 0; i < pow(k, n); i++) {
        int num = i;
        for (int j = n - 1; j >= 0; j--) {
            necklace[j] = num % k;
            num /= k;
        }

        int unique = 1;
        for (int j = 0; j < seen_count; j++) {
            if (are_rotationally_equivalent(necklace, seen[j], n)) {
                unique = 0;
                break;
            }
        }
        
        if (unique) {
            memcpy(seen[seen_count++], necklace, n * sizeof(int));
            for (int j = 0; j < n; j++) {
                printf("%d", necklace[j]);
            }
            printf("\n");
        }
    }

    free(necklace);
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int count_necklaces(int n, int k) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        count += pow(k, gcd(i, n));
    }
    return count / n;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <n> <k>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    int k = atoi(argv[2]);

    printf("Anzahl einzigartiger Halsketten für k=%d, n=%d: %d\n", k, n, count_necklaces(n, k));
    printf("Generierte Halsketten:\n");
    generate_necklaces(n, k);
    
    return 0;
}