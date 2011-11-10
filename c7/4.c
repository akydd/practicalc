/*
 * =============================================================================
 *
 *       Filename:  4.c
 *
 *    Description:  Compute the average of given numbers
 *
 *        Version:  1.0
 *        Created:  11-11-09 09:55:38 PM
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
	int count = 0;
	float total = 0.0;
	float value;
	int result;
	char input[10];

	while(1 == 1) {
		(void)printf("Enter number, or non-number to quit: ");
		(void)fgets(input, sizeof(input), stdin);
		result = sscanf(input, "%f", &value);

		if (result != 1) {
			break;
		}

		total += value;
		count++;
	}

	(void)printf("Average is %f.\n", total / count);
	return 0;
}
