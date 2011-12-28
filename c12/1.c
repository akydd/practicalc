/*
 * =============================================================================
 *
 *       Filename:  1.c
 *
 *    Description:  Use pointers to set each element of an array to 0
 *
 *        Version:  1.0
 *        Created:  11-12-27 12:32:37 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan Kydd (), akydd@ualberta.net
 *        Company:  
 *
 * =============================================================================
 */
#include <stdio.h>

static void print_array(int array[], int length)
{
	int i;
	(void)printf("[");
	for (i = 0; i < length; i++) {
		(void)printf(" %d ", array[i]);
	}
	(void)printf("]\n");
}

static void zero_array(int array[], int length)
{
	int i;
	for (i = 0; i < length; i++) {
		*array = 0;
		array++;
	}
}

int main(void)
{
	int array[] = {1, 2, 3, 4, 5};

	print_array(array, 5);
	zero_array(array, 5);
	print_array(array, 5);
	return 0;
}
