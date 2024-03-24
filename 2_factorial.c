/* Calculate the factorial of a given number. */

#include <stdio.h>

long long int factorial(int n)
{
    if (n < 0)
        return -1; // Error code for negative input
    else if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

int main()
{
    FILE *inputFile, *outputFile;
    int n;

    // Open input file
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL)
    {
        printf("Error opening input file.\n");
        return 1;
    }

    // Open output file
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL)
    {
        printf("Error opening output file.\n");
        fclose(inputFile);
        return 1;
    }

    // Read the number from the input file
    fscanf(inputFile, "%d", &n);

    // Calculate factorial
    long long int result = factorial(n);

    // Write the result to the output file
    if (result == -1)
    {
        fprintf(outputFile, "Invalid input: Factorial of negative numbers is undefined.\n");
    }
    else
    {
        fprintf(outputFile, "Factorial of %d: %lld\n", n, result);
    }

    // Close the files
    fclose(inputFile);
    fclose(outputFile);

    printf("Factorial calculated and written to 'factorial_output.txt' successfully.\n");

    return 0;
}
