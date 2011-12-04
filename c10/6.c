/*
 * =============================================================================
 *
 *       Filename:  6.c
 *
 *    Description:  Shift all set bits in a number to the left.
 *    		    Makes use of count_bits from exercise 4.
 *		    
 *		    Note that shift_bits actually modifies the original number,
 *		    setting bits as appropriate.  It does NOT construct a new
 *		    number and return it in place of the original.
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
static void shift_bits(int*, int);

void shift_bits(int *number_ptr, int count)
{
	int i;
	for (i = 0; i < 32; i++) {
		if (i < count) {
			*number_ptr |= (1<<i);
		} else {
			*number_ptr &= ~(1<<i);
		}
	}
}

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
	int count;

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

		count = count_bits(number);
		(void)printf("%d has %d bits set.\n", number, count);
		shift_bits(&number, count);
		(void)printf("Transformed number is %d.\n", number);
	}
	return 0;
}	
