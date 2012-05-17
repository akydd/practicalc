/*
 * =============================================================================
 *
 *       Filename:  mmult.c
 *
 *    Description:  Defs for matrix mult functions
 *
 *        Version:  1.0
 *        Created:  12-03-19 11:27:24 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan Kydd (), akydd@ualberta.net
 *        Company:  
 *
 * =============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <math.h>
#include "mmult.h"

void identity_matrix(int (*A)[MAX])
{
	int *A_ptr;

	zero_matrix(A);

	for(A_ptr = *A; A_ptr <= *A + (MAX * MAX) - 1; A_ptr += MAX + 1) {
		*A_ptr = 1;
	}
}

void zero_matrix(int (*A)[MAX])
{
	int *A_ptr;

	for(A_ptr = *A; A_ptr <= *A + (MAX * MAX) - 1; A_ptr++) {
		*A_ptr = 0;
	}
}

void randomize_matrix(int (*A)[MAX])
{
	int *A_ptr;
	int limit;

	/* this limit should help avoid int overflows */
	limit = (int)floor(sqrt(INT_MAX / (float)MAX));

	/* seed for rand */
	srand(time(NULL));

	for(A_ptr = *A; A_ptr <= *A + (MAX * MAX) - 1; A_ptr++) {
		/* ensure random sumber is within limit */
		*A_ptr = (int)floor(rand() * (limit / (float)RAND_MAX));
	}
}

void mmult(const int (*A)[MAX], const int (*B)[MAX], int (*C)[MAX])
{
	int i;
	int j;
	int k;

	for(i = 0; i < MAX; i++) {
		for(j = 0; j < MAX; j++) {
			C[i][j] = 0;
			for(k = 0; k < MAX; k++) {
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
}

void mmult_ptr(const int (*A)[MAX], const int (*B)[MAX], int (*C)[MAX])
{
	int *A_ptr;
	int *B_ptr;
	int *C_ptr;
	int i;
	int j;
	int k;

	C_ptr = *C;
	for(i = 0; i < MAX; i++) {
		for(j = 0; j < MAX; j++) {
			*C_ptr = 0;
			A_ptr = *A + i*MAX;
			B_ptr = *B + j;
			for(k = 0; k < MAX; k++) {
				/*
				(void)printf("*A_ptr = %d\n", *A_ptr);
				(void)printf("*B_ptr = %d\n", *B_ptr);
				*/
				
				*C_ptr += *A_ptr * *B_ptr;

				A_ptr++;
				B_ptr += MAX;
			}

			/*
			(void)printf("*C_ptr = %d\n", *C_ptr);
			*/

			C_ptr++;
		}
	}
}

void print_matrix(int (*A)[MAX])
{
	int (*row_ptr)[MAX];
	int *col_ptr;

	for(row_ptr = A; row_ptr <= A + MAX - 1; row_ptr++) {
		(void)printf("[");

		for(col_ptr = *row_ptr;
				col_ptr <= *row_ptr + MAX - 1; col_ptr++) {
			(void)printf(" %d ", *col_ptr);
			
		}

		(void)printf("]\n");
	}
	(void)printf("\n");
}

