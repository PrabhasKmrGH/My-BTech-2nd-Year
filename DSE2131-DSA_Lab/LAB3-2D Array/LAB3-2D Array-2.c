#include <stdio.h>
#include <stdlib.h>

void readMatrix(int **matrix, const int rows, const int cols) {
    printf("Enter elements of matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void transposeMatrix(int **matrix, int **transpose, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
}

int main(void) {
    int rows, cols;
    printf("Enter rows and columns for the matrix: ");
    scanf("%d %d", &rows, &cols);

    // Dynamically allocate matrix
    int **matrix = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) matrix[i] = malloc(cols * sizeof(int));
    int **transpose = malloc(cols * sizeof(int *));
    for (int i = 0; i < cols; i++) transpose[i] = malloc(rows * sizeof(int));

    readMatrix(matrix, rows, cols);

    transposeMatrix(matrix, transpose, rows, cols);

    printf("Original matrix:\n");
    displayMatrix(matrix, rows, cols);
    printf("Transpose of the matrix:\n");
    displayMatrix(transpose, cols, rows);

    // Free allocated memory
    for (int i = 0; i < rows; i++) free(matrix[i]);
    free(matrix);
    for (int i = 0; i < cols; i++) free(transpose[i]);
    free(transpose);

    return 0;
}