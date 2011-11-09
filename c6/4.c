/*
 * =============================================================================
 *
 *       Filename:  4.c
 *
 *    Description:  Add 8% tax to given amount, rounded to nearest penny
 *
 *        Version:  1.0
 *        Created:  11-11-08 08:00:50 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan Kydd (), akydd@ualberta.net
 *        Company:  
 *
 * =============================================================================
 */
#include <stdio.h>

int main(void)
{
	char input[10];
	float price;
	float tax = 0.08;
	float price_after_tax;
	int result;

	do {
		(void)printf("Enter amount: ");
		(void)fgets(input, sizeof(input), stdin);
		result = sscanf(input, "%f", &price);
	} while (result != 1);

	price_after_tax = price * (1.0 + tax);
	(void)printf("%.2f with %f tax is %.2f.\n", \
		price, tax, price_after_tax);

	return 0;
}
