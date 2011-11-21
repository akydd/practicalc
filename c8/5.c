/*
 * =============================================================================
 *
 *       Filename:  5.c
 *
 *    Description:  int max_value(int[], int) returns the max value of an array
 *    		    of given length.
 *
 *        Version:  1.0
 *        Created:  11-11-20 07:21:39 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan Kydd (), akydd@ualberta.net
 *        Company:  
 *
 * =============================================================================
 */
#include <stdio.h>

static int max_value(int[], int);

int max_value(int array[], int length)
{
	int i;
	int max = array[0];

	for(i = 1; i < length; i++) {
		if (array[i] > max) {
			max = array[i];
		}
	}
	return max;
}

int main(void)
{
	/* lets test this! */
	int array1[] = {-9, 0, 2, 9};
	int array2[] = {100, 10, 0, -10};
	int array3[] = {2, 2, 2};

	(void)printf("Max of array1 should be 9.  It is %d.\n",
			max_value(array1, 4));
	(void)printf("Max of array2 should be 100.  It is %d.\n",
			max_value(array2, 4));
	(void)printf("Max of array3 should be 2.  It is %d.\n",
			max_value(array3, 3));

	return 0;
}
