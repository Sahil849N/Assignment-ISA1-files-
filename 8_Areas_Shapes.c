/*  Calculate the area of shapes like rectangle, triangle, and circle.*/
#include <stdio.h>
#include <math.h>
#define pi 3.14159265359

void calculateArea(FILE *inputFile, FILE *outputFile) {
    int ch;
    float area, slant_height, height, breadth, radii, base, side, length;
    while (fscanf(inputFile, "%d", &ch) != EOF) {
        switch (ch) {
            case 1:
                fscanf(inputFile, "%f%f", &length, &breadth);
                area = length * breadth;
                break;

            case 2:
                fscanf(inputFile, "%f%f", &height, &base);
                area = (base * height) / 2.0;
                break;

            case 3:
                fscanf(inputFile, "%f", &radii);
                area = pi * pow(radii, 2);
                break;

            case 4:
                fscanf(inputFile, "%f", &side);
                area = pow(side, 2);
                break;

            case 5:
                fscanf(inputFile, "%f%f", &height, &radii);
                area = 2 * pi * radii * (height + radii);
                break;

            case 6:
                fscanf(inputFile, "%f", &side);
                area = pow(side, 3);
                break;

            case 7:
                fscanf(inputFile, "%f%f%f", &length, &breadth, &height);
                area = length * breadth * height;
                break;

            case 8:
                fscanf(inputFile, "%f", &radii);
                area = 4 * pi * pow(radii, 2);
                break;

            case 9:
                fscanf(inputFile, "%f", &radii);
                area = 3 * pi * pow(radii, 2);
                break;

            default:
                fprintf(outputFile, "Invalid\n");
                continue;
        }
        fprintf(outputFile, "AREA : %f square units\n", area);
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

    calculateArea(inputFile, outputFile);

    fclose(inputFile);
    fclose(outputFile);

    printf("Results written to 'area_shapes_output.txt' successfully.\n");

    return 0;
}
