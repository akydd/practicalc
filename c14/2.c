/*
 * =============================================================================
 *
 *       Filename:  2.c
 *
 *    Description:  Matrix multipliers
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
#include <sys/time.h>
#include "mmult.h"

int main(void)
{
	/* used to time multiplication calls */
	struct timeval *start_time;
	struct timeval *end_time;

	int **A = create_randomized_matrix();
	(void)sleep(1);
	int **B = create_randomized_matrix();

	/* time mmult with indeces */
	gettimeofday(start_time, NULL);
	int **AB = mmult((const int**)A, (const int**)B);
	gettimeofday(end_time, NULL);

	print_matrix(A);
	print_matrix(B);
	print_matrix(AB);

	free_matrix(AB);

	(void)printf("Mult using indeces took %d microseconds.\n",
			(int)(end_time->tv_usec - start_time->tv_usec));

	/* time mmult with ptrs */
	gettimeofday(start_time, NULL);
	AB = mmult_ptr((const int**)A, (const int**)B);
	gettimeofday(end_time, NULL);

	(void)printf("Mult using ptrs took %d microseconds.\n",
			(int)(end_time->tv_usec - start_time->tv_usec));

	free_matrix(A);
	free_matrix(B);
	free_matrix(AB);

	return 0;
}
