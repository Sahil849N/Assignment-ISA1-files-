/*  Determine whether a given number is prime.*/

#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is prime
bool isPrime(long long int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

int main() {
    FILE *inputFile, *outputFile;
    long long int n;

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
        fclose(inputFile);
        return 1;
    }

    // Read the number from the input file
    fscanf(inputFile, "%lld", &n);

    // Check if the number is prime
    bool result = isPrime(n);

    // Write the result to the output file
    if (result)
        fprintf(outputFile, "%lld is prime.\n", n);
    else
        fprintf(outputFile, "%lld is not prime.\n", n);

    // Close the files
    fclose(inputFile);
    fclose(outputFile);

    printf("Result written to 'prime_output.txt' successfully.\n");

    return 0;
}
