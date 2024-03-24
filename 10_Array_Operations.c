/*  Perform operations like finding the largest/smallest element, sum,
and average of an array.*/
#include <stdio.h>
#include <stdlib.h>

void performOperations(FILE *inputFile, FILE *outputFile) {
    int n, ch, sum = 0, maxi = 0, mini = 0;
    float avg = 0;

    fscanf(inputFile, "%d", &n);
    int array[n];

    for (int i = 0; i < n; i++)
        fscanf(inputFile, "%d", &array[i]);

    maxi = mini = array[0];

    while (1) {
        fscanf(inputFile, "%d", &ch);
        if (feof(inputFile)) // Check for end of file
            break;

        switch (ch) {
            case 1:
                sum = 0;
                for (int i = 0; i < n; i++)
                    sum += array[i];
                fprintf(outputFile, "Sum: %d\n", sum);
                break;

            case 2:
                sum = 0;
                for (int i = 0; i < n; i++)
                    sum += array[i];
                avg = (float)sum / n;
                fprintf(outputFile, "Average: %.2f\n", avg);
                break;

            case 3:
                maxi = array[0];
                for (int i = 1; i < n; i++) {
                    if (maxi < array[i])
                        maxi = array[i];
                }
                fprintf(outputFile, "Largest: %d\n", maxi);
                break;

            case 4:
                mini = array[0];
                for (int i = 1; i < n; i++) {
                    if (mini > array[i])
                        mini = array[i];
                }
                fprintf(outputFile, "Smallest: %d\n", mini);
                break;

            default:
                fprintf(outputFile, "Invalid choice\n");
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

    performOperations(inputFile, outputFile);

    fclose(inputFile);
    fclose(outputFile);

    printf("Results written to 'array_operations_output.txt' successfully.\n");

    return 0;
}
