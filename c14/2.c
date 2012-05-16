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
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
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

	//randomize_matrix(A);
	identity_matrix(A);
	(void)sleep(1);
	//randomize_matrix(B);
	identity_matrix(B);

	print_matrix(A);
	print_matrix(B);

	/* time mmult with indeces */
	start = clock();
	mmult((const int (*)[MAX])A, (const int (*)[MAX]) B, C);
	end = clock();
	diff = (double) (end - start) / CLOCKS_PER_SEC;

	print_matrix(C);

	(void)printf("Mult using indeces took %f seconds.\n", diff);

	/* time mmult with ptrs */
	start = clock();
	mmult_ptr((const int (*)[MAX])A, (const int (*)[MAX])B, D);
	end = clock();
	diff = (double) (end - start) / CLOCKS_PER_SEC;

	print_matrix(D);

	(void)printf("Mult using ptrs took %f seconds.\n", diff);

	return 0;
}
