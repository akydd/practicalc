/*
 * =====================================================================================
 *
 *       Filename:  1.c
 *
 *    Description:  Convert Imperial units to metric
 *
 *        Version:  1.0
 *        Created:  11-11-06 09:43:45 AM
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
	int option;
	float imp_value;

	float conversions[] = { 2.54, 0.3048, 0.9144, 1.6093, \
		0.56038, 4.5461, 28.35, 0.4536, 6.3503 };

	while (1)
	{
		/* clear input buffer */
		input[0] = "\0";

		(void) printf("To convert, type the menu option followed by ");
		(void) printf("the value you wish to convert\n");
		(void) printf(" 1. inches to centimeters\n");
		(void) printf(" 2. feet to meters\n");
		(void) printf(" 3. yards to meters\n");
		(void) printf(" 4. miles to kilometers\n");
		(void) printf(" 5. pints to liters\n");
		(void) printf(" 6. gallons to liters\n");
		(void) printf(" 7. ounces to grams\n");
		(void) printf(" 8. pounds to kilograms\n");
		(void) printf(" 9. stone to kilograms\n");
		(void) printf("Type '0' to quit.\n");

		(void) fgets(input, sizeof(input), stdin);
		int scanned = (sscanf(input, "%d %f", &option, &imp_value));

		if (scanned == 2) {
			if ((option <= 9) && (option >= 0)) {
				(void) printf("%f converts to %f.\n\n", imp_value, imp_value * conversions[option-1]);
			} else {
				(void)printf("Invalid options.\n\n");
			}
		} else if (scanned == 1) {
			if (option == 0) {
				break;
			} else {
				(void)printf("Invalid option.\n\n");
			}
		} else {
			(void)printf("Invalid options.\n\n");
		}
	}

	(void) printf("Bye!\n");
	return 0;
}
