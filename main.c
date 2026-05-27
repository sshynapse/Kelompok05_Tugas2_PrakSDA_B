#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utils.h"
#include "basic_sorting.h"
#include "advance_sorting.h"

int main() {
    int pilihan, metode;
    int arr[SIZE];
    char words[MAX_WORDS][MAX_LEN];
    int totalWords;

    srand(time(NULL));

    do {
        printf("\n===== MAIN MENU =====\n");
        printf("1. Basic Sorting\n");
        printf("2. Advanced Sorting\n");
        printf("3. Exit\n");
        printf("Choose Menu: ");
        scanf("%d", &pilihan);

        // ================= BASIC =================
        if (pilihan == 1) {
            generateRandomData(arr, SIZE);
            shuffleInt(arr, SIZE);

            printf("\n===== BASIC SORTING =====\n");
            printf("1. Bubble Sort\n");
            printf("2. Insertion Sort\n");
            printf("3. Selection Sort\n");
            printf("4. Back\n");
            printf("Choose Method: ");
            scanf("%d", &metode);

            if (metode >= 1 && metode <= 3) {

                int sample[10];
                for (int i = 0; i < 10; i++) sample[i] = arr[i];

                printf("\nFirst 10 numbers BEFORE Sorting:\n");
                displayInt(sample, 10);

                if (metode == 1) bubbleSort(sample, 10);
                else if (metode == 2) insertionSort(sample, 10);
                else if (metode == 3) selectionSort(sample, 10);

                printf("\nFirst 10 numbers AFTER Sorting (ascending):\n");
                displayInt(sample, 10);

                clock_t start = clock();

                if (metode == 1) bubbleSort(arr, SIZE);
                else if (metode == 2) insertionSort(arr, SIZE);
                else if (metode == 3) selectionSort(arr, SIZE);

                clock_t end = clock();

                printf("\nVerification: %s\n",
                    isSortedInt(arr, SIZE) ? "Sorted correctly" : "FAILED");

                printf("Execution Time: %f seconds\n",
                    (double)(end - start) / CLOCKS_PER_SEC);
            }
        }

        // ================= ADVANCED =================
        else if (pilihan == 2) {
            totalWords = loadWords(words);
            if (totalWords == 0) continue;

            shuffleString(words, totalWords);

            printf("\n===== ADVANCED SORTING =====\n");
            printf("1. Merge Sort\n");
            printf("2. Quick Sort\n");
            printf("3. Shell Sort\n");
            printf("4. Back\n");
            printf("Choose Method: ");
            scanf("%d", &metode);

            if (metode >= 1 && metode <= 3) {

                char sample[10][MAX_LEN];
                for (int i = 0; i < 10; i++)
                    strcpy(sample[i], words[i]);

                printf("\nFirst 10 words BEFORE Sorting:\n");
                displayString(sample, 10);

                if (metode == 1) mergeSort(sample, 0, 9);
                else if (metode == 2) quickSort(sample, 0, 9);
                else if (metode == 3) shellSort(sample, 10);

                printf("\nFirst 10 Words AFTER Sorting (ascending):\n");
                displayString(sample, 10);

                clock_t start = clock();

                if (metode == 1) mergeSort(words, 0, totalWords - 1);
                else if (metode == 2) quickSort(words, 0, totalWords - 1);
                else if (metode == 3) shellSort(words, totalWords);

                clock_t end = clock();

                printf("\nVerification: %s\n",
                    isSortedString(words, totalWords) ? "Sorted correctly" : "FAILED");

                printf("Execution Time: %f seconds\n",
                    (double)(end - start) / CLOCKS_PER_SEC);
            }
        }

    } while (pilihan != 3);

    printf("\nProgram Finished...\n");
    return 0;
}