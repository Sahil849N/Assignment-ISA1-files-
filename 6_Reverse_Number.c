/*  Reverse the digits of a given number.*/
#include <stdio.h>
#include<stdlib.h>
int main() {
    FILE *inputFile, *outputFile;
    int n, d = 0, s = 0;

    // Open input file
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Open output file
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        // Close input file if it was successfully opened
        fclose(inputFile);
        return 1;
    }

    // Read number from input file
    fscanf(inputFile, "%d", &n);

    // Reverse the number
    while (n != 0) {
        d = n % 10;
        s = (s * 10) + d;
        n = n / 10;
    }

    // Write reversed number to output file
    fprintf(outputFile, "Reversed number is: %d\n", s);

    // Close files
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
