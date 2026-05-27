#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

void swapInt(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapString(char a[][MAX_LEN], int i, int j) {
    char temp[MAX_LEN];
    strcpy(temp, a[i]);
    strcpy(a[i], a[j]);
    strcpy(a[j], temp);
}

void generateRandomData(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }
}

void shuffleInt(int arr[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swapInt(&arr[i], &arr[j]);
    }
}

void shuffleString(char arr[][MAX_LEN], int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swapString(arr, i, j);
    }
}

void displayInt(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

void displayString(char arr[][MAX_LEN], int n) {
    for (int i = 0; i < n; i++) printf("%s\n", arr[i]);
}

int isSortedInt(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) return 0;
    }
    return 1;
}

int isSortedString(char arr[][MAX_LEN], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (strcmp(arr[i], arr[i + 1]) > 0) return 0;
    }
    return 1;
}

int loadWords(char words[][MAX_LEN]) {
    FILE *f = fopen("words.txt", "r");
    if (f == NULL) {
        printf("Cannot open words.txt file!\n");
        return 0;
    }

    int count = 0;
    while (fscanf(f, "%s", words[count]) != EOF && count < MAX_WORDS) {
        count++;
    }

    fclose(f);
    return count;
}
