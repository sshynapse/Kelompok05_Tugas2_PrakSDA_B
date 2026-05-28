#include <string.h>
#include "advance_sorting.h"
#include "utils.h"

void merge(char arr[][MAX_LEN], int left, int mid, int right) {
    int i = left, j = mid + 1, k = 0;
    char temp[MAX_WORDS][MAX_LEN];

    while (i <= mid && j <= right) {
        if (strcmp(arr[i], arr[j]) <= 0)
            strcpy(temp[k++], arr[i++]);
        else
            strcpy(temp[k++], arr[j++]);
    }

    while (i <= mid) strcpy(temp[k++], arr[i++]);
    while (j <= right) strcpy(temp[k++], arr[j++]);

    for (i = left, k = 0; i <= right; i++, k++) {
        strcpy(arr[i], temp[k]);
    }
}

void mergeSort(char arr[][MAX_LEN], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int partition(char arr[][MAX_LEN], int low, int high) {
    char pivot[MAX_LEN];
    strcpy(pivot, arr[high]);

    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (strcmp(arr[j], pivot) < 0) {
            i++;
            swapString(arr, i, j);
        }
    }

    swapString(arr, i + 1, high);
    return i + 1;
}

void quickSort(char arr[][MAX_LEN], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void shellSort(char arr[][MAX_LEN], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            char temp[MAX_LEN];
            strcpy(temp, arr[i]);

            int j;
            for (j = i; j >= gap && strcmp(arr[j - gap], temp) > 0; j -= gap) {
                strcpy(arr[j], arr[j - gap]);
            }

            strcpy(arr[j], temp);
        }
    }
}