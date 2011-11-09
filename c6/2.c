/*
 * =============================================================================
 *
 *       Filename:  2.c
 *
 *    Description:  Find the # days between two after epoch calendar dates.
 *    		    Dates must be fomatted as YYYY-MM-DD
 *
 *        Version:  1.0
 *        Created:  11-11-06 02:44:53 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan Kydd (), akydd@ualberta.net
 *        Company:  
 *
 * =============================================================================
 */

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int main(void)
{
	char input[20];
	char input1[20];;
	const char *d1, *d2;

	struct tm tm_1, tm_2;

	int diff;

	(void) printf("Enter first date (YYYY-MM-DD): ");
	(void) fgets(input, sizeof(input), stdin);
	/*  strip newline */
	input[(strlen(input))-1] = '\0';
	d1 = strptime(input, "%F", &tm_1);

	(void) printf("Enter second date (YYYY-MM-DD): ");
	(void) fgets(input1, sizeof(input1), stdin);
	/* strip newline */
	input[(strlen(input1))-1] = '\0';
	d2 = strptime(input1, "%F", &tm_2);

	/* Checking here is tricky...
	 * strptime returns NULL pointer if no input fields can be matched,
	 * but will point to a non \0 char if there is only a partial match.
	 * 
	 * We want a complete match, so we check both conditions, but we
	 * have to check for the NULL pointer first, otherwise we risk a seg
	 * fault for trying to check if the  pointer (which could be NULL) is
	 * pointing to a non \0 character.
	 *
	 * I have assumed that the compiler will always check the left
	 * condition before the right.  I don't know if this is true.
	 */
	if ((d1 == NULL) || (*d1 != '\0')) {
		printf("The first input date is invalid.\n");
	} else if ((d2 == NULL) || (*d1 != '\0')) {
		printf("The second input date is invalid.\n");
	} else {
		(void) printf("0x%x\n", *d1);
		/*  calculate days diff based on year and days since jan 1 */
		if (tm_1.tm_year > tm_2.tm_year) {
			diff = (tm_1.tm_year - tm_2.tm_year) * 365 + \
			       tm_1.tm_yday - tm_2.tm_yday;
		} else if (tm_2.tm_year > tm_1.tm_year) {
			diff = (tm_2.tm_year - tm_1.tm_year) * 365 + \
			       tm_2.tm_yday - tm_1.tm_yday;
		} else {
			diff = abs(tm_1.tm_yday - tm_2.tm_yday);
		}

		(void) printf("There are %d days between.\n", diff);
	}

	return 0;
}
