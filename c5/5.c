/*
 * =====================================================================================
 *
 *       Filename:  5.c
 *
 *    Description:  A program to tell if a given year is a leap year
 *
 *        Version:  1.0
 *        Created:  11-11-05 11:09:04 PM
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
	int year;
	int leap_year_bool = 0;

	printf("Enter the year: ");
	fgets(input, sizeof(input), stdin);
	sscanf(input, "%d", &year);

	if ((year % 4) == 0)
	{
		if ((year % 100) == 0)
		{
			if ((year % 400) != 0)
			{
				leap_year_bool = 0;
			}
			else
			{
				leap_year_bool = 1;
			}
		}
		else
		{
			leap_year_bool = 1;
		}
	}
	else
	{
		leap_year_bool = 0;
	}

	if (leap_year_bool)
		printf("%d is a leap year.\n", year);
	else
		printf("%d is not a leap year.\n", year);

	return 0;
}
