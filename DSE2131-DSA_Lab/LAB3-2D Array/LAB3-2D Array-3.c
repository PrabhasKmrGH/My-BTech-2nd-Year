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


bool isUpperTriangular(int **matrix, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (matrix[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

int main(void) {
    int n;
    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);

    // Dynamically allocate square matrix
    int **matrix = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrix[i] = malloc(n * sizeof(int));
    }

    readMatrix(matrix, n, n);

    if (isUpperTriangular(matrix, n)) {
        printf("The matrix is upper triangular.\n");
    } else {
        printf("The matrix is not upper triangular.\n");
    }

    // Free allocated memory
    for (int i = 0; i < n; i++) free(matrix[i]);
    free(matrix);

    return 0;
}