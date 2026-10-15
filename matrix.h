/*
 * CSE 220 Homework 5: matrix operations with pointer arithmetic.
 *
 * Do not change this file.
 *
 * In every function, D is a dimensions array. Its entries always come in
 * (rows, columns) pairs, in the order the matrices appear in the signature.
 */
#ifndef MATRIX_H
#define MATRIX_H

/*
 * Builds the sparse representation S of M.
 * D is {rows of M, columns of M}. S is 3 by max(rows, columns).
 * Returns the number of non zero elements, or -1 when M is not sparse.
 */
int SparseMatrix(const int D[2], const int M[D[0]][D[1]],
                 int S[3][(D[1] > D[0] ? D[1] : D[0])]);

/*
 * Element wise product of M and N, written into A.
 * D is {rows of M, cols of M, rows of N, cols of N, rows of A, cols of A}.
 * Returns 1, 2, -1, -2 or -3 as described in the assignment.
 */
int HadamardProduct(const int D[6], const int M[D[0]][D[1]],
                    const int N[D[2]][D[3]], int A[D[4]][D[5]]);

/*
 * Matrix product of M and N, written into A.
 * D is laid out exactly as it is for HadamardProduct.
 * Returns 1, 2, -1, -2 or -3 as described in the assignment.
 */
int Multiplication(const int D[6], const int M[D[0]][D[1]],
                   const int N[D[2]][D[3]], int A[D[4]][D[5]]);

/*
 * Diagonal, row and column sums of A, written into DS.
 * D is {rows of A, cols of A, rows of DS, cols of DS}.
 * Returns 1, 2 or -1 as described in the assignment.
 */
int DiagonalSum(const int D[4], const int A[D[0]][D[1]], int DS[D[2]][D[3]]);

#endif
