/*
 * =============================================================================
 *
 *       Filename:  4.c
 *
 *    Description:  Count the number of bits set in the binary representation
 *    		    of an int, not counting the sign bit.
 *
 *        Version:  1.0
 *        Created:  11-11-24 08:40:09 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan Kydd (), akydd@ualberta.net
 *        Company:  
 *
 * =============================================================================
 */
#include <stdio.h>

static int count_bits(int);

int count_bits(int number)
{
	int count = 0;
	int bit;

	/* better to shift bit than number.
	 * We can guarantee that bit >= 0 always. */
	for(bit = 1; bit >= 0; bit <<= 1) {
		if ((number & bit) == bit) {
			count++;
		}
	}
	return count;
}

int main(void)
{
	char input[10];
	int number;
	int result;

	while(1 == 1) {
		/* clear the buffer */
		input[0] = '\0';

		(void)printf("Enter a number, or non number to quit: ");
		(void)fgets(input, sizeof(input), stdin);
		result = sscanf(input, "%d", &number);

		if (result != 1) {
			(void)printf("Bye!\n");
			break;
		}

		(void)printf("%d has %d bits set.\n", number, count_bits(number));
	}
	return 0;
}	
