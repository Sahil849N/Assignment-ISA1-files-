/*  Search for an element in a sorted array using binary search.*/

#include <stdio.h>

int binarySearch(int array[], int size, int value) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = (right + left) / 2;
        if (array[mid] == value) {
            return mid;
        } else if (array[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
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
    int result = binarySearch(array, n, num);
    if (result != -1) {
        fprintf(outputFile, "Value %d found at index %d\n", num, result);
    } else {
        fprintf(outputFile, "Value %d not found\n", num);
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Results written to 'binary_search_output.txt' successfully.\n");

    return 0;
}
