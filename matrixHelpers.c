/*
 * CSE 220 Homework 5: helper functions for checking your work.
 * Provided for you. Do not change this file.
 */
#include <stdio.h>
#include "matrixHelpers.h"

int matricesEqual(int rows, int cols, const int A[rows][cols], const int B[rows][cols])
{
    int i, j;

    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            if (A[i][j] != B[i][j])
                return 0;
    return 1;
}

void printMatrix(const char *label, int rows, int cols, const int M[rows][cols])
{
    int i, j;

    printf("%s (%d by %d):\n", label, rows, cols);
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
            printf("%6d", M[i][j]);
        printf("\n");
    }
}
