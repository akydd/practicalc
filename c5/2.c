/*
 * =====================================================================================
 *
 *       Filename:  2.c
 *
 *    Description:  Exercise 5.2 and 5.3, where input is integer
 *
 *        Version:  1.0
 *        Created:  11-11-05 04:56:42 PM
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
	int percent;

	char grade = 'F';
	char sign = ' ';

	int remainder;

	printf("Enter grade: ");
	fgets(input, sizeof(input), stdin);
	sscanf(input, "%d", &percent);
	
	remainder = percent % 10;

	/* assign the letter grade */
	if (percent > 90)
		grade = 'A';
	else if (percent > 80)
		grade = 'B';
	else if (percent > 70)
		grade = 'C';
	else if (percent > 60) 
		grade = 'D';

	/* assign the sign for non 'F' grade*/
	if (grade != 'F') {
		if (remainder >= 8)
			sign = '+';
		else if (remainder >= 4)
			sign = ' ';
		else if (remainder >= 1)
			sign = '-';
		else if (remainder == 0)
			sign = '+';
	}

	printf("Percentage %d gets a grade of %c%c.\n", percent, grade, sign);

	return 0;
}
