/*
 * =============================================================================
 *
 *       Filename:  3.c
 *
 *    Description:  Recursive function 'count' counts the # of times a given\
 *    		    number appears in given array.
 *
 *        Version:  1.0
 *        Created:  11-11-20 06:14:05 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan Kydd (), akydd@ualberta.net
 *        Company:  
 *
 * =============================================================================
 */
#include <stdio.h>

static int count(int, int[], int);

int count(int number, int array[], int length)
{
	int the_count = 0;

	if (length == 0) {
		return the_count;
	}

	if (array[length - 1] == number) {
		the_count++;
	}

	return the_count + count(number, array, length - 1);
}

int main(void)
{
	/* let's test this! */
	int empty_array[0];
	int test_array[7] = {1, 2, 3, 4, 5, 5, 6};

	(void)printf("Count for empty [] is %d.\n", count(3, empty_array, 0));
	(void)printf("Count for 7 is %d.\n", count(7, test_array, 7));
	(void)printf("Count for 1 is %d.\n", count(1, test_array, 7));
	(void)printf("Count for 5 is %d.\n", count(5, test_array, 7));

	return 0;
}
