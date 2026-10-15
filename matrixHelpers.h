/*
 * CSE 220 Homework 5: helper functions for checking your work.
 *
 * These are provided for you. Do not change this file, and do not call these
 * from inside matrix.c. They are meant for your Criterion tests and for
 * printing a matrix while you debug.
 */
#ifndef MATRIX_HELPERS_H
#define MATRIX_HELPERS_H

/*
 * Returns 1 when the two matrices hold exactly the same values, 0 otherwise.
 * Use it in a test like:
 *     cr_assert(matricesEqual(2, 3, A, expected));
 */
int matricesEqual(int rows, int cols, const int A[rows][cols], const int B[rows][cols]);

/*
 * Prints a matrix with a label in front of it, for debugging. Example:
 *     printMatrix("A after the call", 2, 3, A);
 */
void printMatrix(const char *label, int rows, int cols, const int M[rows][cols]);

#endif
