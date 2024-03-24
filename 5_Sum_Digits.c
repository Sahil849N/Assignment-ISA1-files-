/*  Calculate the sum of digits of a given number.*/
#include <stdio.h>

// Function to calculate the sum of digits of a given number
int sumOfDigits(int n) {
    int sum = 0, digit;
    while (n != 0) {
        digit = n % 10;
        sum += digit;
        n /= 10;
    }
    return sum;
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

    int number;
    fscanf(inputFile, "%d", &number);

    int sum = sumOfDigits(number);

    fprintf(outputFile, "Sum of digits of %d: %d\n", number, sum);

    fclose(inputFile);
    fclose(outputFile);

    printf("Sum of digits calculated and written to 'sum_of_digits_output.txt' successfully.\n");

    return 0;
}
