/*
 * =============================================================================
 *
 *       Filename:  8.c
 *
 *    Description:  itos converts non-negative integers < 100 into words.
 *
 *        Version:  1.0
 *        Created:  11-11-19 23:15:53 PM
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
	int divisor;
	int remainder;

	if ( (number <= 100) && (number >= 0) ) {

		/* boundary cases */
		if (number == 100) {
			(void)strcat(s, "one hundred");
		} else if (number == 0) {
			(void)strcat(s, "zero");
		} else {
			/* handle numbers from 1 to 99 */
			divisor = number / 10;
			remainder = number % 10; 

			/* numbers >= 20 */
			if (divisor >= 2) {
				switch (divisor) {
					case 9:
						(void)strcat(s, "ninety");
						break;
					case 8:
						(void)strcat(s, "eighty");
						break;
					case 7:
						(void)strcat(s, "seventy");
						break;
					case 6:
						(void)strcat(s, "sixty");
						break;
					case 5:
						(void)strcat(s, "fifty");
						break;
					case 4:
						(void)strcat(s, "fourty");
						break;
					case 3:
						(void)strcat(s, "thirty");
						break;
					case 2:
						(void)strcat(s, "twenty");
						break;
					default:
						(void)printf("wft?");
				}
			} else if (divisor == 1) {
				/* less than 20, greater or equal to 10 */
				switch (number) {
					case 19:
						(void)strcat(s, "nineteen");
						break;
					case 18:
						(void)strcat(s, "eighteen");
						break;
					case 17:
						(void)strcat(s, "seventeen");
						break;
					case 16:
						(void)strcat(s, "sixteen");
						break;
					case 15:
						(void)strcat(s, "fifteen");
						break;
					case 14:
						(void)strcat(s, "fourteen");
						break;
					case 13:
						(void)strcat(s, "thirteen");
						break;
					case 12:
						(void)strcat(s, "twelve");
						break;
					case 11:
						(void)strcat(s, "eleven");
						break;
					case 10:
						(void)strcat(s, "ten");
						break;
				}
			}
			
			/* handle the remainders */
			if (divisor != 1) {

				/* hyphen */
				if ( (divisor > 1) && (remainder != 0) ) {
					(void)strcat(s, "-");
				}

				switch (remainder) {
					case 1:
						(void)strcat(s, "one");
						break;
					case 2:
						(void)strcat(s, "two");
						break;
					case 3:
						(void)strcat(s, "three");
						break;
					case 4:
						(void)strcat(s, "four");
						break;
					case 5:
						(void)strcat(s, "five");
						break;
					case 6:
						(void)strcat(s, "six");
						break;
					case 7:
						(void)strcat(s, "seven");
						break;
					case 8:
						(void)strcat(s, "eight");
						break;
					case 9:
						(void)strcat(s, "nine");
						break;
				}
			}
		}

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
