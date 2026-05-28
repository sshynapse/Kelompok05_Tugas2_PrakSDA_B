#ifndef ADVANCE_SORTING_H
#define ADVANCE_SORTING_H

#include "utils.h"

void mergeSort(char arr[][MAX_LEN], int left, int right);
void quickSort(char arr[][MAX_LEN], int low, int high);
void shellSort(char arr[][MAX_LEN], int n);

#endif