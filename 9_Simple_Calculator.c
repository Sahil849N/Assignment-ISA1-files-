/*  Implement a basic calculator with arithmetic operations.*/
#include <stdio.h>
#include <math.h>

void performOperation(FILE *inputFile, FILE *outputFile) {
    char ch;
    float n1, n2, res;
    while (fscanf(inputFile, " %c", &ch) != EOF) {
        fscanf(inputFile, "%f%f", &n1, &n2);
        switch (ch) {
            case '+':
                res = n1 + n2;
                break;

            case '-':
                res = n1 - n2;
                break;

            case '*':
                res = n1 * n2;
                break;

            case '/':
                if (n2 != 0) {
                    res = n1 / n2;
                } else {
                    fprintf(outputFile, "Error: Division by zero\n");
                    continue; // Move to next iteration
                }
                break;

            case '^':
                res = pow(n1, n2);
                break;

            default:
                fprintf(outputFile, "Invalid operation\n");
                continue; // Move to next iteration
        }
        fprintf(outputFile, "Result: %.2f\n", res);
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

    performOperation(inputFile, outputFile);

    fclose(inputFile);
    fclose(outputFile);

    printf("Results written to 'calculator_output.txt' successfully.\n");

    return 0;
}
