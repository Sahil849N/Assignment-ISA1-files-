/*  Sort an array using the selection sort algorithm.*/

#include <stdio.h>

void selectionSort(int array[], int size) {
    for (int i = 0; i < size; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[min]) {
                min = j;
            }
        }
        int temp = array[i];
        array[i] = array[min];
        array[min] = temp;
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

    selectionSort(array, size);

    fprintf(outputFile, "Sorted array: ");
    for (int i = 0; i < size; i++) {
        fprintf(outputFile, "%d ", array[i]);
    }
    fprintf(outputFile, "\n");

    fclose(inputFile);
    fclose(outputFile);

    printf("Sorted array written to 'selection_sort_output.txt' successfully.\n");

    return 0;
}
