/*
 * =============================================================================
 *
 *       Filename:  5.c
 *
 *    Description:  Check if a number is prime
 *
 *        Version:  1.0
 *        Created:  11-11-08 10:03:59 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan Kydd (), akydd@ualberta.net
 *        Company:  
 *
 * =============================================================================
 */
#include <stdio.h>
#include <math.h>

int main(void)
{
	char input[10];
	int x;
	int result;
	int is_prime;

	do {
		(void)printf("Enter number: ");
		(void)fgets(input, sizeof(input), stdin);
		result = sscanf(input, "%d", &x);
	} while (result != 1);

	/* TODO: try to divide x by all positive numbers <= sqrt(x)  */
	return 0;
}
