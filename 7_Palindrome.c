/*  Check if a given number or string is a palindrome*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxi 100

int isPalindrome(int num) {
    int d = num, r, s = 0;
    while (num) {
        r = num % 10;
        s = r + (s * 10);
        num = num / 10;
    }
    if (d == s)
        return 1;
    return 0;
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

    int ch, num, flag = 1;
    char str[maxi];
    while (1) {
        fscanf(inputFile, "%d", &ch);
        if (feof(inputFile)) // Check for end of file
            break;
        switch (ch) {
            case 1:
                fscanf(inputFile, "%d", &num);
                int result = isPalindrome(num);
                if (result == 1)
                    fprintf(outputFile, "%d is Palindrome\n", num);
                else
                    fprintf(outputFile, "%d is Not Palindrome\n", num);
                break;

            case 2:
                fscanf(inputFile, "%s", str);
                int size = strlen(str);
                int i = 0;
                flag = 1; // Reset flag for each string
                while (i < size / 2) {
                    if (str[i] != str[size - i - 1]) {
                        flag = 0;
                        break;
                    }
                    i++;
                }
                if (flag)
                    fprintf(outputFile, "%s is Palindrome\n", str);
                else
                    fprintf(outputFile, "%s is Not Palindrome\n", str);
                break;

            default:
                fprintf(outputFile, "Invalid Choice\n");
                break;
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Results written to 'palindrome_output.txt' successfully.\n");

    return 0;
}
