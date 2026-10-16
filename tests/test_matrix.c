/*
 * CSE 220 Homework 5 tests.
 *
 * Name: Justin Seto
 * SBU ID: 117203453
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

 // Spare Matrix tests
 Test(SparseMatrix, all_zeros_edge_case)
{
    const int D[2] = {3, 3};
    const int M[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
    int S[3][3] = {{0}};
    int expected[3][3] = {{0,0,0},{0,0,0},{0,0,0}};

    cr_assert_eq(SparseMatrix(D, M, S), 0);
    cr_assert(matricesEqual(3, 3, S, expected));
}

Test(SparseMatrix, single_element_1x1)
{
    const int D[2] = {1, 1};
    const int M[1][1] = {{5}};
    int S[3][1] = {{0}};
    int expected[3][1] = {{0},{0},{5}};

    cr_assert_eq(SparseMatrix(D, M, S), 1);
    cr_assert(matricesEqual(3, 1, S, expected));
}

Test(SparseMatrix, wide_matrix_with_negative_entries)
{
    const int D[2] = {2, 5};
    const int M[2][5] = {{0,0,3,0,0},{0,-7,0,0,1}};
    int S[3][5] = {{0}};
    int expected[3][5] = {{0,1,1,0,0},{2,1,4,0,0},{3,-7,1,0,0}};

    cr_assert_eq(SparseMatrix(D, M, S), 3);
    cr_assert(matricesEqual(3, 5, S, expected));
}

// Hamarand Product Tests
Test(HadamardProduct, compatible_output_larger_in_both)
{
    const int D[6] = {2,2,2,2,3,3};
    const int M[2][2] = {{1,2},{5,6}};
    const int N[2][2] = {{3,4},{7,8}};
    int A[3][3] = {{0}};
    int expected[3][3] = {{3,8,0},{35,48,0},{0,0,0}};

    cr_assert_eq(HadamardProduct(D, M, N, A), 2);
    cr_assert(matricesEqual(3, 3, A, expected));
}

Test(HadamardProduct, compatible_output_too_small)
{
    const int D[6] = {2,3,2,3,1,2};
    const int M[2][3] = {{1,2,3},{4,5,6}};
    const int N[2][3] = {{2,3,4},{5,6,7}};
    int A[1][2] = {{0}};
    int expected[1][2] = {{2,6}};

    cr_assert_eq(HadamardProduct(D, M, N, A), -3);
    cr_assert(matricesEqual(1, 2, A, expected));
}

Test(HadamardProduct, incompatible_output_can_hold_overlap)
{
    const int D[6] = {3,3,2,2,3,3};
    const int M[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    const int N[2][2] = {{2,5},{1,4}};
    int A[3][3] = {{0}};
    int expected[3][3] = {{2,10,0},{4,20,0},{0,0,0}};

    cr_assert_eq(HadamardProduct(D, M, N, A), -1);
    cr_assert(matricesEqual(3, 3, A, expected));
}

Test(HadamardProduct, single_element_1x1)
{
    const int D[6] = {1,1,1,1,1,1};
    const int M[1][1] = {{3}};
    const int N[1][1] = {{-4}};
    int A[1][1] = {{0}};
    int expected[1][1] = {{-12}};

    cr_assert_eq(HadamardProduct(D, M, N, A), 1);
    cr_assert(matricesEqual(1, 1, A, expected));
}

// Multiplication tests
Test(Multiplication, incompatible_output_cannot_hold)
{
    const int D[6] = {3,2,3,2,2,2};
    const int M[3][2] = {{2,3},{5,4},{2,3}};
    const int N[3][2] = {{3,3},{7,2},{1,5}};
    int A[2][2] = {{0}};
    int expected[2][2] = {{27,12},{43,23}};

    cr_assert_eq(Multiplication(D, M, N, A), -2);
    cr_assert(matricesEqual(2, 2, A, expected));
}

Test(Multiplication, incompatible_output_can_hold)
{
    const int D[6] = {3,2,3,2,4,3};
    const int M[3][2] = {{2,3},{5,4},{2,3}};
    const int N[3][2] = {{3,3},{7,2},{1,5}};
    int A[4][3] = {{0}};
    int expected[4][3] = {{27,12,0},{43,23,0},{27,12,0},{0,0,0}};

    cr_assert_eq(Multiplication(D, M, N, A), -1);
    cr_assert(matricesEqual(4, 3, A, expected));
}

Test(Multiplication, compatible_output_larger_in_both)
{
    const int D[6] = {3,2,2,3,4,4};
    const int M[3][2] = {{2,3},{5,4},{2,3}};
    const int N[2][3] = {{3,2,1},{1,3,4}};
    int A[4][4] = {{0}};
    int expected[4][4] = {{9,13,14,0},{19,22,21,0},{9,13,14,0},{0,0,0,0}};

    cr_assert_eq(Multiplication(D, M, N, A), 2);
    cr_assert(matricesEqual(4, 4, A, expected));
}

Test(Multiplication, single_element_1x1)
{
    const int D[6] = {1,1,1,1,1,1};
    const int M[1][1] = {{-3}};
    const int N[1][1] = {{-4}};
    int A[1][1] = {{0}};
    int expected[1][1] = {{12}};

    cr_assert_eq(Multiplication(D, M, N, A), 1);
    cr_assert(matricesEqual(1, 1, A, expected));
}

// DiagonalSum Tests
Test(DiagonalSum, square_output_larger_in_both)
{
    const int D[4] = {2,2,5,4};
    const int A[2][2] = {{2,4},{6,8}};
    int DS[5][4] = {{0}};
    int expected[5][4] = {{10,10,0,0},{8,12,0,0},{6,0,0,0},{14,0,0,0},{0,0,0,0}};

    cr_assert_eq(DiagonalSum(D, A, DS), 2);
    cr_assert(matricesEqual(5, 4, DS, expected));
}

Test(DiagonalSum, non_square_rectangular_exact_fit)
{
    const int D[4] = {2,3,4,3};
    const int A[2][3] = {{3,5,7},{2,4,6}};
    int DS[4][3] = {{0}};
    int expected[4][3] = {{7,0,0},{5,9,13},{15,0,0},{12,0,0}};

    cr_assert_eq(DiagonalSum(D, A, DS), 1);
    cr_assert(matricesEqual(4, 3, DS, expected));
}

Test(DiagonalSum, output_too_small_truncates)
{
    const int D[4] = {4,4,2,2};
    const int A[4][4] = {{1,2,3,4},{5,6,7,8},{9,1,2,3},{4,5,6,7}};
    int DS[2][2] = {{0}};
    int expected[2][2] = {{16,16},{19,14}};

    cr_assert_eq(DiagonalSum(D, A, DS), -1);
    cr_assert(matricesEqual(2, 2, DS, expected));
}

Test(DiagonalSum, single_element_1x1)
{
    const int D[4] = {1,1,3,2};
    const int A[1][1] = {{7}};
    int DS[3][2] = {{0}};
    int expected[3][2] = {{7,7},{7,0},{7,0}};

    cr_assert_eq(DiagonalSum(D, A, DS), 1);
    cr_assert(matricesEqual(3, 2, DS, expected));
}