/*  Search for an element in an array using linear search.*/

#include <stdio.h>

int search(int array[], int size, int val) {
    for (int i = 0; i < size; i++) {
        if (array[i] == val) {
            return i;
        }
    }
    return -1;
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

    int n, num;
    fscanf(inputFile, "%d", &n);
    int array[n];
    for (int i = 0; i < n; i++)
        fscanf(inputFile, "%d", &array[i]);
    fscanf(inputFile, "%d", &num);
    int result = search(array, n, num);
    if (result != -1) {
        fprintf(outputFile, "Value %d found at index %d\n", num, result);
    } else {
        fprintf(outputFile, "Value %d not found\n", num);
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Results written to 'linear_search_output.txt' successfully.\n");

    return 0;
}
