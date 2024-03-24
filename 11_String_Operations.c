/*  Manipulate strings such as concatenation, copying, and comparison.*/

#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 100

void concatenateStrings(char *str1, char *str2, FILE *outputFile) {
    strcat(str1, str2);
    fprintf(outputFile, "Concatenated string: %s\n", str1);
}

void copyString(char *str1, char *str2, FILE *outputFile) {
    strcpy(str1, str2);
    fprintf(outputFile, "Copied string: %s\n", str1);
}

void compareStrings(char *str1, char *str2, FILE *outputFile) {
    int result = strcmp(str1, str2);
    if (result == 0)
        fprintf(outputFile, "Strings are equal.\n");
    else if (result < 0)
        fprintf(outputFile, "String 1 is lexicographically smaller than String 2.\n");
    else
        fprintf(outputFile, "String 1 is lexicographically greater than String 2.\n");
}

int main() {
    char str1[MAX_LENGTH], str2[MAX_LENGTH];
    int ch;

    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE *outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        fclose(inputFile);
        return 1;
    }

    printf("Enter string 1 : ");
    fgets(str1, MAX_LENGTH, inputFile);
    if (strchr(str1, '\n') != NULL)
        *strchr(str1, '\n') = '\0';

    printf("Enter string 2: ");
    fgets(str2, MAX_LENGTH, inputFile);
    if (strchr(str2, '\n') != NULL)
        *strchr(str2, '\n') = '\0';

    printf("Enter 1 : Concatenate Strings\nEnter 2 : Copy String 2 to String 1\nEnter 3 : Compare Strings\n");
    while(1){
    fscanf(inputFile, "%d", &ch);
    if (feof(inputFile)) // Check for end of file
            break;
    switch (ch) {
        case 1:
            concatenateStrings(str1, str2, outputFile);
            break;
        case 2:
            copyString(str1, str2, outputFile);
            break;
        case 3:
            compareStrings(str1, str2, outputFile);
            break;
        default:
            fprintf(outputFile, "Invalid choice.\n");
            break;
    }
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Results written to 'string_manipulation_output.txt' successfully.\n");

    return 0;
}
