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

void multiplyMatrices(int **a, int **b, int **result, int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main(void) {
    int matrixARows, matrixACols, matrixBRows, matrixBCols;
    printf("Enter rows and columns for first matrix: ");
    scanf("%d %d", &matrixARows, &matrixACols);
    printf("Enter rows and columns for second matrix: ");
    scanf("%d %d", &matrixBRows, &matrixBCols);

    if (matrixACols != matrixBRows) {
        printf("Matrix multiplication not possible. Columns of first matrix must equal rows of second.\n");
        return 1;
    }

    // Dynamically allocate matrices
    int **a = malloc(matrixARows * sizeof(int *));
    for (int i = 0; i < matrixARows; i++) a[i] = malloc(matrixACols * sizeof(int));
    int **b = malloc(matrixBRows * sizeof(int *));
    for (int i = 0; i < matrixBRows; i++) b[i] = malloc(matrixBCols * sizeof(int));
    int **result = malloc(matrixARows * sizeof(int *));
    for (int i = 0; i < matrixARows; i++) result[i] = malloc(matrixBCols * sizeof(int));

    readMatrix(a, matrixARows, matrixACols);
    readMatrix(b, matrixBRows, matrixBCols);

    multiplyMatrices(a, b, result, matrixARows, matrixACols, matrixBCols);

    printf("Resultant of Matrix multiplication:\n");
    displayMatrix(result, matrixARows, matrixBCols);

    // Free allocated memory
    for (int i = 0; i < matrixARows; i++) free(a[i]);
    free(a);
    for (int i = 0; i < matrixBRows; i++) free(b[i]);
    free(b);
    for (int i = 0; i < matrixARows; i++) free(result[i]);
    free(result);

    return 0;
}