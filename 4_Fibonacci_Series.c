/*  Generate the Fibonacci series up to a certain limit*/
#include <stdio.h>

// Function to generate and write Fibonacci series up to a limit to a file
void generateFibonacciSeries(int limit, FILE *filePointer) {
    int p = 0, q = 1, fibo = 0;

    if (limit <= 0) {
        fprintf(filePointer, "Invalid input. Limit must be a positive integer.\n");
        return;
    }
    else if (limit == 1) {
        fprintf(filePointer, "0\n");
        return;
    }

    fprintf(filePointer, "0\n1\n");

    for (int i = 2; i < limit; i++) {
        fibo = p + q;
        p = q;
        q = fibo;
        fprintf(filePointer, "%d\n", fibo);
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

    int limit;
    fscanf(inputFile, "%d", &limit);

    generateFibonacciSeries(limit, outputFile);

    fclose(inputFile);
    fclose(outputFile);

    printf("Fibonacci series up to %d has been written to 'fibonacci_series.txt' successfully.\n", limit);

    return 0;
}
