/*
 * =============================================================================
 *
 *       Filename:  3.c
 *
 *    Description:  Sum the elements in an array.  Optimized using registered
 *    		    ptrs instead of array indeces.
 *
 *        Version:  1.0
 *        Created:  12-05-19 03:22:58 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan Kydd (), akydd@ualberta.net
 *        Company:  
 *
 * =============================================================================
 */

#include <stdio.h>

#define SIZE 10

int main()
{
	register int sum = 0;
	int num_array[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11};
	register int *element;

	for(element = num_array; element < num_array + SIZE; element++) {
		sum += *element;
	}

	(void)printf("Sum is %d.\n", sum);
	return 0;
}
