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

void identity_matrix(int (*)[MAX]);

void zero_matrix(int (*)[MAX]);

void randomize_matrix(int (*)[MAX]);

void mmult(int (*)[MAX], int (*)[MAX], int (*)[MAX]);

void mmult_ptr(int (*)[MAX], int (*)[MAX], int (*)[MAX]);

void print_matrix(int (*)[MAX]);
