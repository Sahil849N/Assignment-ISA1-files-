/*  Sort an array using the bubble sort algorithm.*/

#include <stdio.h>
#include <stdbool.h>

void bubbleSort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        bool swap = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swap = true;
            }
        }
        if (!swap) {
            break;
        }
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

    int n;
    fscanf(inputFile, "%d", &n);
    int array[n];
    for (int i = 0; i < n; i++)
        fscanf(inputFile, "%d", &array[i]);

    bubbleSort(array, n);

    fprintf(outputFile, "Sorted array: ");
    for (int i = 0; i < n; i++) {
        fprintf(outputFile, "%d ", array[i]);
    }
    fprintf(outputFile, "\n");

    fclose(inputFile);
    fclose(outputFile);

    printf("Sorted array written to 'bubble_sort_output.txt' successfully.\n");

    return 0;
}
