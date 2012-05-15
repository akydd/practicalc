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

void identity_matrix(int *A)
{
	int *A_ptr;

	zero_matrix(A);

	for(A_ptr = A; A_ptr <= A + (MAX - 1) + (MAX - 1); A_ptr += MAX + 2) {
		*A_ptr = 1;
	}
}

void zero_matrix(int *A)
{
	int *A_ptr;

	for(A_ptr = A; A_ptr <= A + (MAX - 1) * (MAX - 1); A_ptr++) {
		*A_ptr = 0;
	}
}

void randomize_matrix(int *A)
{
	int *A_ptr;
	int limit;

	/* this limit should help avoid int overflows */
	limit = (int)floor(sqrt(INT_MAX / (float)MAX));

	/* seed for rand */
	srand(time(NULL));

	for(A_ptr = A; A_ptr <= A + (MAX - 1) * (MAX - 1); A_ptr++) {
		/* ensure random sumber is within limit */
		*A_ptr = (int)floor(rand() * (limit / (float)RAND_MAX));
	}
}

void mmult(const int *A, const int *B, int *C)
{
	int i;
	int j;
	int k;

	for(i = 0; i < MAX; i++) {
		for(j = 0; j < MAX; j++) {
			int sum = 0;
			for(k = 0; k < MAX; k++) {
				sum += A[i][k] * B[k][j];
			}
			AB[i][j] = sum;
		}
	}
}

void mmult_ptr(const int *A, const int *B, int *C)
{
}

void print_matrix(int *A)
{
	int i;
	int j;

	for (i = 0; i < MAX; i++) {
		for (j = 0; j < MAX; j++) {
			if (j == 0) {
				(void)printf("[");
			}
			(void)printf(" %d ", A[i][j]);
			if (j == (MAX - 1)) {
				(void)printf("]\n");
			}
		}
	}
	(void)printf("\n");
}

