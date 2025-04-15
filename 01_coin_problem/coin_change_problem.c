#include <stdio.h>
#include <stdlib.h>

unsigned long long counter = 0;

void print_array(int arr[], int size) {
    for (int i = size - 1; i >= 0; i--) {
        if (arr[i] != 0) printf("%d ", arr[i]);
    }
    printf("\n");
}

// Iterative Funktion, die alle Kombinationen zählt und sie anzeigt
void generate_compositions(int n)
{
    int arr[n];
    int k = 0;
    for (int i = 0; i < n; i++) {
        arr[i] = 1;
    }
    while (1) {
        counter++;
        // print_array(arr, n);
        if (arr[k] == n) return;
        arr[k]--;
        arr[k+1]++;
        if (arr[k] > 1) {
            int tmp = arr[k];
            for (int i = 1; i <= tmp; i++) {
                arr[k] = 1;
                k--;
            }
        }
        if (arr[k] >= 1) k--; 
        k++;
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Bitte eine Zahl als Parameter angeben.\n");
        return 1;
    }

    int n = atoi(argv[1]);
    if (n <= 0)
    {
        printf("Bitte eine positive Zahl eingeben.\n");
        return 1;
    }

    generate_compositions(n);

    printf("Counter: %lld\n", counter);

    return 0;
}