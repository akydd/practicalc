/*
 * =====================================================================================
 *
 *       Filename:  4.c
 *
 *    Description:  Compute the minimum # of quarters, nickels, dimes and
 *    pennies needed to produce the given amount of cents. 
 *
 *        Version:  1.0
 *        Created:  11-11-05 10:39:21 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan Kydd (), akydd@ualberta.net
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>

int main(void)
{
	char input[10];
	int cents, cents_copy = 0;
	int num_quarters, num_dimes, num_nickles = 0;

	printf("Enter the amount of cents: ");
	fgets(input, sizeof(input), stdin);
	sscanf(input, "%d", &cents);
	cents_copy = cents;

	num_quarters = cents / 25;
	cents -= num_quarters * 25;

	num_dimes = cents / 10;
	cents -= num_dimes * 10;

	num_nickles = cents / 5;
	cents -= num_nickles * 5;

	printf("%d cents requires:\n", cents_copy);
	printf("%d quarters,\n", num_quarters);
	printf("%d dimes,\n", num_dimes);
	printf("%d nickles,\n", num_nickles);
	printf("and %d pennies.\n", cents);

	return 0;
}
