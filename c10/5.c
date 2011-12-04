/*
 * =============================================================================
 *
 *       Filename:  5.c
 *
 *    Description:  Splits a 32 bit int into 8 four bit values.
 *    		    
 *    		    Doesn't actually return such values, as a 4-bit datatype is
 *    		    not defined in C.  Instead, main ouputs the 4-bit hex
 *    		    representation of each of the 8-bit segments of a 32 bit
 *    		    int.
 *
 *        Version:  1.0
 *        Created:  11-12-03 12:52:55 PM
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
	int number;
	int i;
	int result;
	int tester = 0x0000000F; /* use to test the last 4 bits of an int */

	while (1 == 1) {
		(void)printf("Enter a number, non-number to quit: ");
		(void)fgets(input, sizeof(input), stdin);
		result = sscanf(input, "%d", &number);

		if (result != 1) {
			break;
		}

		(void)printf("Original number in hex is %x.\n", number);

		for (i = 0; i < 8; i++) {
			(void)printf("4 bit value in hex is %x.\n",
					number & tester);

			/* ok to shift, because we only test the last 4 bits */
			number = number>>4;
		}
	}

	return 0;
}
