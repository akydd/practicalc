/*
 * =============================================================================
 *
 *       Filename:  mmult.h
 *
 *    Description:  Matrix multiplication methods for nxn matrices
 *
 *        Version:  1.0
 *        Created:  12-03-19 11:21:58 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan Kydd (), akydd@ualberta.net
 *        Company:  
 *
 * =============================================================================
 */

/* default matrix size of 3x3 */
#ifndef MAX
#define MAX 3
#endif

void free_matrix(int **);

int **create_empty_matrix(void);

int **create_identity_matrix(void);

int **create_zero_matrix(void);

int **create_randomized_matrix(void);

int **mmult(const int **, const int **);

int **mmult_ptr(const int **, const int **);

void print_matrix(int **);
