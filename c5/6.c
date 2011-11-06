/*
 * =====================================================================================
 *
 *       Filename:  6.c
 *
 *    Description:  calculate weekly pay, given hrs worked and rate.
 *    OT rate is 1.5 reg, and overtime is any hours over 40.
 *
 *        Version:  1.0
 *        Created:  11-11-05 11:58:54 PM
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
	float hours, rate;
	float ot_rate = 1.5;
	float reg_hours = 40.0;
	float pay = 0;

	printf("Enter the number of hours and wage: ");
	fgets(input, sizeof(input), stdin);
	sscanf(input, "%f %f", &hours, &rate);

	if (hours > reg_hours)
	{
		pay = reg_hours * rate + (hours - reg_hours) * rate * ot_rate;
	}
	else
	{
		pay = hours * rate;
	}

	printf("Pay for %f hours worked is %f.\n", hours, pay);

	return 0;
}
