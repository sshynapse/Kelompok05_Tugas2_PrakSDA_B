#ifndef UTILS_H
#define UTILS_H

#define SIZE 1000
#define MAX_WORDS 5000
#define MAX_LEN 100

void swapInt(int *a, int *b);
void swapString(char a[][MAX_LEN], int i, int j);

void generateRandomData(int arr[], int n);
void shuffleInt(int arr[], int n);
void shuffleString(char arr[][MAX_LEN], int n);

void displayInt(int arr[], int n);
void displayString(char arr[][MAX_LEN], int n);

int isSortedInt(int arr[], int n);
int isSortedString(char arr[][MAX_LEN], int n);

int loadWords(char words[][MAX_LEN]);

#endif
