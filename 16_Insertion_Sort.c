/*  Sort an array using the insertion sort algorithm.*/

#include <stdio.h>

void insertionSort(int array[], int size) {
    for (int i = 1; i < size; i++) {
        int insertIndex = i;
        int currentValue = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > currentValue) {
            array[j + 1] = array[j];
            insertIndex = j;
            j--;
        }
        array[insertIndex] = currentValue;
    }
}

int main() {
    FILE *inputFile, *outputFile;
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        fclose(inputFile);
        return 1;
    }

    int size;
    fscanf(inputFile, "%d", &size);
    int array[size];
    for (int i = 0; i < size; i++)
        fscanf(inputFile, "%d", &array[i]);

    insertionSort(array, size);

    fprintf(outputFile, "Sorted array: ");
    for (int i = 0; i < size; i++) {
        fprintf(outputFile, "%d ", array[i]);
    }
    fprintf(outputFile, "\n");

    fclose(inputFile);
    fclose(outputFile);

    printf("Sorted array written to 'insertion_sort_output.txt' successfully.\n");

    return 0;
}
