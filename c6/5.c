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
	int i;
	int is_prime = 1;

	do {
		(void)printf("Enter number: ");
		(void)fgets(input, sizeof(input), stdin);
		result = sscanf(input, "%d", &x);
	} while (result != 1);

	if (x > 0) {

		/* 
		 * try to divide x by all positive numbers <= sqrt(x) and > 1.
		 * If x is divisble by any of those numbers, x is not prime.
		 */
		for(i = (int)floor(sqrt(x)); i > 1; i--) {
			if ( (x % i) == 0 ) {
				is_prime = 0;
				break;
			}
		}

		if (is_prime == 0) {
			(void)printf("%d is not prime.\n", x);
		} else {
			(void)printf("%d is prime!\n", x);
		}

	} else {
		(void)printf("x must be a natural number.\n");
	}
	return 0;
}
