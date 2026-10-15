/*
 * CSE 220 Homework 5 tests.
 *
 * Name:
 * SBU ID:
 *
 * A few sample tests are given so you can see how Criterion and the provided
 * helpers are used. They fail until you implement the functions, which is
 * expected.
 *
 * You must add your own tests: at least 5 for each of the 4 functions, so 20
 * in total. Check the output matrix, not only the return value, and cover the
 * edge cases: a 1 by 1 matrix, a matrix of all zeros, an output matrix that is
 * too small, and inputs whose dimensions do not match.
 *
 * Build and run these with:   make test
 */
#include <criterion/criterion.h>
#include "matrix.h"
#include "matrixHelpers.h"

Test(SparseMatrix, counts_and_stores_non_zero_entries)
{
    const int D[2] = {4, 2};
    const int M[4][2] = {{0,4},{0,5},{0,0},{2,0}};
    int S[3][4] = {{0}};
    int expected[3][4] = {{0,1,3,0},{1,1,0,0},{4,5,2,0}};

    cr_assert_eq(SparseMatrix(D, M, S), 3);
    cr_assert(matricesEqual(3, 4, S, expected));
}

Test(SparseMatrix, reports_a_matrix_that_is_not_sparse)
{
    const int D[2] = {4, 4};
    const int M[4][4] = {{2,3,0,5},{3,0,3,1},{4,0,3,0},{0,0,6,0}};
    int S[3][4] = {{0}};
    int zeros[3][4] = {{0}};

    cr_assert_eq(SparseMatrix(D, M, S), -1);
    cr_assert(matricesEqual(3, 4, S, zeros));
}

Test(HadamardProduct, multiplies_element_by_element)
{
    const int D[6] = {2,3,2,3,2,3};
    const int M[2][3] = {{1,2,3},{4,5,6}};
    const int N[2][3] = {{2,3,4},{5,6,7}};
    int A[2][3] = {{0}};
    int expected[2][3] = {{2,6,12},{20,30,42}};

    cr_assert_eq(HadamardProduct(D, M, N, A), 1);
    cr_assert(matricesEqual(2, 3, A, expected));
}

Test(Multiplication, multiplies_two_compatible_matrices)
{
    const int D[6] = {3,2,2,3,3,3};
    const int M[3][2] = {{2,3},{5,4},{2,3}};
    const int N[2][3] = {{3,2,1},{1,3,4}};
    int A[3][3] = {{0}};
    int expected[3][3] = {{9,13,14},{19,22,21},{9,13,14}};

    cr_assert_eq(Multiplication(D, M, N, A), 1);
    cr_assert(matricesEqual(3, 3, A, expected));
}

Test(DiagonalSum, sums_a_square_matrix)
{
    const int D[4] = {3,3,5,3};
    const int A[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int DS[5][3] = {{0}};
    int expected[5][3] = {{15,15,0},{12,15,18},{6,0,0},{15,0,0},{24,0,0}};

    cr_assert_eq(DiagonalSum(D, A, DS), 1);
    cr_assert(matricesEqual(5, 3, DS, expected));
}

/*
 * TODO: add your own tests below.
 *
 * You still need more tests for all four functions. Useful assertions:
 *   cr_assert_eq(actual, expected)                       two values are equal
 *   cr_assert(matricesEqual(rows, cols, got, expected))  a whole matrix matches
 *   cr_assert(condition)                                 the condition is true
 *
 * printMatrix("A after the call", 2, 3, A) prints a matrix while you debug.
 */
