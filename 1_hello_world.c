/* Print "Hello, World!" to the console */

#include <stdio.h>
int main()
{
    FILE *filePointer;
    filePointer = fopen("output.txt", "w"); // Open a file named "output.txt" in write mode

    if (filePointer == NULL)
    {
        printf("Unable to create file.\n");
        return 1;
    }

    fprintf(filePointer, "Hello, World!\n"); // Write "Hello, World!" to the file

    fclose(filePointer); // Close the file

    printf("Data written to the file successfully.\n");

    return 0;
}

