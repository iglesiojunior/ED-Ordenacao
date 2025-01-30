#include <stdio.h>
#include <stdlib.h>

void merge(int array[], int left, int middle, int right) {
    int *tempArray = (int *)malloc((right - left + 1) * sizeof(int));
    if (tempArray == NULL) abort();

    int indexLeft = left, indexRight = middle + 1, indexTemp = 0;
    while (indexLeft <= middle && indexRight <= right) {
        if (array[indexLeft] < array[indexRight]) {
            tempArray[indexTemp++] = array[indexLeft++];
        } else {
            tempArray[indexTemp++] = array[indexRight++];
        }
    }
    while (indexLeft <= middle) {
        tempArray[indexTemp++] = array[indexLeft++];
    }
    while (indexRight <= right) {
        tempArray[indexTemp++] = array[indexRight++];
    }
    for (int i = left; i <= right; i++) {
        array[i] = tempArray[i - left];
    }

    free(tempArray);
}

void mergeSort(int array[], int left, int right) {
    if (left == right) return;

    int middle = (left + right) / 2;
    mergeSort(array, left, middle);
    mergeSort(array, middle + 1, right);
    merge(array, left, middle, right);
}

int main() {
    int array[] = {10, 4, 56, 11, 1};
    int arraySize = sizeof(array) / sizeof(array[0]);

    printf("Original array: ");
    for (int i = 0; i < arraySize; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    mergeSort(array, 0, arraySize - 1);

    printf("Sorted array: ");
    for (int i = 0; i < arraySize; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
