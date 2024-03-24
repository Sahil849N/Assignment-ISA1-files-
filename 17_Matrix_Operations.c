/*  Perform matrix addition, subtraction, multiplication, and transpose.*/

#include <stdio.h>
#include <stdlib.h>

#define ROW 2
#define COL 2

void add(int mat1[ROW][COL], int mat2[ROW][COL], FILE *outputFile) {
    int ans[ROW][COL];
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++)
            ans[i][j] = mat1[i][j] + mat2[i][j];
    }
    fprintf(outputFile, "Matrix Addition:\n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++)
            fprintf(outputFile, "%d ", ans[i][j]);
        fprintf(outputFile, "\n");
    }
}

void sub(int mat1[ROW][COL], int mat2[ROW][COL], FILE *outputFile) {
    int ans[ROW][COL];
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++)
            ans[i][j] = mat1[i][j] - mat2[i][j];
    }
    fprintf(outputFile, "Matrix Subtraction:\n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++)
            fprintf(outputFile, "%d ", ans[i][j]);
        fprintf(outputFile, "\n");
    }
}

void mul(int mat1[ROW][COL], int mat2[ROW][COL], FILE *outputFile) {
    int ans[ROW][COL];
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            ans[i][j] = 0;
            for (int k = 0; k < COL; k++)
                ans[i][j] += mat1[i][k] * mat2[k][j];
        }
    }
    fprintf(outputFile, "Matrix Multiplication:\n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++)
            fprintf(outputFile, "%d ", ans[i][j]);
        fprintf(outputFile, "\n");
    }
}

void transpose(int mat[ROW][COL], FILE *outputFile) {
    int trans[COL][ROW];
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++)
            trans[j][i] = mat[i][j];
    }
    fprintf(outputFile, "Matrix Transpose:\n");
    for (int i = 0; i < COL; i++) {
        for (int j = 0; j < ROW; j++)
            fprintf(outputFile, "%d ", trans[i][j]);
        fprintf(outputFile, "\n");
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

    int ch;
    int mat1[ROW][COL], mat2[ROW][COL];

    // Read matrix 1 from input file
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++)
            fscanf(inputFile, "%d", &mat1[i][j]);
    }

    // Read matrix 2 from input file
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++)
            fscanf(inputFile, "%d", &mat2[i][j]);
    }

    while (1) {
        fscanf(inputFile, "%d", &ch);
        if (feof(inputFile)) // Check for end of file
            break;
        switch (ch) {
            case 1:
                add(mat1, mat2, outputFile);
                break;
            case 2:
                sub(mat1, mat2, outputFile);
                break;
            case 3:
                mul(mat1, mat2, outputFile);
                break;
            case 4:
                printf("Enter the matrix you want to transpose (1 or 2): ");
                int matrixChoice;
                fscanf(inputFile, "%d", &matrixChoice);
                if (matrixChoice == 1)
                    transpose(mat1, outputFile);
                else if (matrixChoice == 2)
                    transpose(mat2, outputFile);
                else
                    fprintf(outputFile, "Invalid choice.\n");
                break;
            case 5:
                printf("Exiting program.\n");
                fclose(inputFile);
                fclose(outputFile);
                return 0;
            default:
                fprintf(outputFile, "Invalid choice.\n");
        }
    }

    fclose(inputFile);
    fclose(outputFile);
    return 0;
}
