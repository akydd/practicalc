/*
 * =============================================================================
 *
 *       Filename:  7.c
 *
 *    Description:  itos converts non-negative integers into words.
 *
 *        Version:  1.0
 *        Created:  11-11-19 08:33:53 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan Kydd (), akydd@ualberta.net
 *        Company:  
 *
 * =============================================================================
 */
#include <stdio.h>
#include <string.h>
#include <math.h>

static char *itos(int, char*);

char *itos(int number, char *s)
{
	int i;
	int divisor;
	int base;

	for (i = (int)floor(log10((double)number)); i >= 0; i--) {
		
		base = (int)pow((double)10, (double)i);
		divisor = number / base;

		switch (divisor) {
			case 9:
				(void)strcat(s, "nine");
				break;
			case 8:
				(void)strcat(s, "eight");
				break;
			case 7:
				(void)strcat(s, "seven");
				break;
			case 6:
				(void)strcat(s, "six");
				break;
			case 5:
				(void)strcat(s, "five");
				break;
			case 4:
				(void)strcat(s, "four");
				break;
			case 3:
				(void)strcat(s, "three");
				break;
			case 2:
				(void)strcat(s, "two");
				break;
			case 1:
				(void)strcat(s, "one");
				break;
			default:
				(void)strcat(s, "zero");
		}

		/* need a space sometimes */
		if (i > 0) {
			(void)strcat(s, " ");
		}

		number = (int)fmod((double)number, (double)base); 
	}
	return s;
}

int main(void)
{
	char input[10];
	char string[200];
	int number;
	int result;

	while (1 == 1) {
		/*  null out the string */
		string[0] = '\0';

		/* read in the number */
		(void)printf("Enter a number (non number to quit): ");
		(void)fgets(input, sizeof(input), stdin);
		result = sscanf(input, "%d", &number);

		/* if we didn't get a number, quit. */
		if (result != 1) {
			break;
		}

		/* call the itos method */
		(void)itos(number, string);
		(void)printf("Number %d converted to string is %s.\n",
			       	number, string);
	}

	return 0;
}
