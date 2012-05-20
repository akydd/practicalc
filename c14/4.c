/*
 * =============================================================================
 *
 *       Filename:  4.c
 *
 *    Description:  Counts the number of bits in a char array
 *    		    To make:
 *    		    gcc -Wall -Wextra -pedantic -o 4 4.c -lm
 *    		    Optional flags: -DSIZE=<size>, -DPRINT
 *
 *        Version:  1.0
 *        Created:  12-05-19 07:54:17 PM
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
#include <math.h>
#include <time.h>

#ifndef SIZE
#define SIZE 10
#endif

int main(void)
{
	char array[SIZE];
	char *char_ptr;
	clock_t start;
	clock_t end;
	double diff;
	register int num_bits = 0;
	register int bit_tester;

	/* seed random numbers */
	srand((unsigned int)time(NULL));
	
	/* initialize the array */
	for (char_ptr = array; char_ptr < array + SIZE; char_ptr++) {
#ifdef DEBUG
		*char_ptr = ' ';
#endif
#ifndef DEBUG
		/* 
		 * Random character:
		 * Printable chars have dec vals from 32 to 126.
		 * So pick a random int from 0 to 126 - 32, then add
		 * 32, and cast result to a char.
		 */
		int random_int = (int)floor((double)rand()
				* (94 / (float)RAND_MAX) + 32);
		*char_ptr = (char)random_int;
#endif
#ifdef PRINT
		(void)printf(" %d ", random_int);
		(void)printf(" '%c' ", *char_ptr);
#endif
	}

	/* count bits in array and time the process */
	start = clock();
	for (char_ptr = array; char_ptr < array + SIZE; char_ptr++) {
		for(bit_tester = 0x80; bit_tester > 0; bit_tester >>= 1) {
			if (((int)*char_ptr & bit_tester) == bit_tester) {
				num_bits++;
			}
		}
	}
	end = clock();
	diff = (double) (end - start) / CLOCKS_PER_SEC;

	(void)printf("\nNumber of bits is %d.\n", num_bits);
	(void)printf("Time to count bits in a %d element array: %f secs.\n",
			SIZE, diff);

	return 0;
}
