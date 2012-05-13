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

void free_matrix(int **matrix)
{
	int i;
	for (i = 0; i < MAX; i++) {
		free(matrix[i]);
	}
	free(matrix);
}

int **create_empty_matrix(void)
{
	int i;
	/* must initialize as int **, not as int [][] */
	/* First allocate memory for an int * to each row */
	int **matrix = malloc(sizeof(int *) * MAX);
	
	if (matrix == NULL) {
		exit(EXIT_FAILURE);
	}
	
	/* Then for each row, allocate enough memory for all the cols */
	for(i = 0; i < MAX; i++) {
		matrix[i] = malloc(sizeof(int) * MAX);
		if (matrix[i] == NULL) {
			exit(EXIT_FAILURE);
		}
	}

	return matrix;
}

int **create_identity_matrix(void)
{
	int **matrix = create_empty_matrix();
	int i;
	int j;

	for (i = 0; i < MAX; i++) {
		for (j = 0; j < MAX; j++) {
			if (i == j) {
				matrix[i][j] = 1;
			} else {
				matrix[i][j] = 0;
			}
		}
	}
	return matrix;
}

int **create_zero_matrix(void)
{
	int **matrix = create_empty_matrix();
	int i;
	int j;

	for (i = 0; i < MAX; i++) {
		for (j = 0; j < MAX; j++) {
			matrix[i][j] = 0;
		}
	}
	return matrix;
}

int **create_randomized_matrix(void)
{
	int i;
	int j;
	int **matrix = create_empty_matrix();
	/* this limit should help avoid int overflows */
	int limit = (int)floor(sqrt(INT_MAX / (float)MAX));

	/* seed for rand */
	srand(time(NULL));

	for (i = 0; i < MAX; i++) {
		for (j = 0; j < MAX; j++) {
			/* ensure random sumber is within limit */
			matrix[i][j] =
				(int)floor(rand() * (limit / (float)RAND_MAX));
		}
	}
	return matrix;
}

int **mmult(const int **A, const int **B)
{
	int **AB = create_empty_matrix();

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
	return AB;
}

int **mmult_ptr(const int **A, const int **B)
{
	/* TODO: implement this */
	return mmult(A, B);
}

void print_matrix(int **A)
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
