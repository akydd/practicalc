/*
 * =============================================================================
 *
 *       Filename:  2.c
 *
 *    Description:  Test two ways of multiplying static matrices
 *
 *        Version:  1.0
 *        Created:  12-03-19 11:08:30 PM
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
#include <time.h>
/*  #include <unistd.h> */
#include "mmult.h"

int main(void)
{
	int A[MAX][MAX];
	int B[MAX][MAX];
	int C[MAX][MAX];
	int D[MAX][MAX];

	/* used to time multiplication calls */
	clock_t start;
	clock_t end;
	double diff;

	randomize_matrix(A);
/*  	(void)sleep(1); */
	randomize_matrix(B);

#ifdef DEBUG
	print_matrix(A);
	print_matrix(B);
#endif

	/* time mmult with indeces */
	start = clock();
	mmult(A, B, C);
	end = clock();
	diff = (double) (end - start) / CLOCKS_PER_SEC;

#ifdef DEBUG
	print_matrix(C);
#endif

	(void)printf("Mult %d by %d using indeces took %f seconds.\n",
			MAX, MAX, diff);

	/* time mmult with ptrs */
	start = clock();
	mmult_ptr(A, B, D);
	end = clock();
	diff = (double) (end - start) / CLOCKS_PER_SEC;

#ifdef DEBUG
	print_matrix(D);
#endif

	(void)printf("Mult %d by %d using ptrs took %f seconds.\n",
			MAX, MAX, diff);

	return 0;
}
