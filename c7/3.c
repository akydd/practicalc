/*
 * =============================================================================
 *
 *       Filename:  3.c
 *
 *    Description:  Compute the resistance for an arbitrary # of resistors
 *
 *        Version:  1.0
 *        Created:  11-11-09 09:32:55 PM
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
	float inv_resistance = 0.0;
	char input[10];
	float resistance;
	int result;

	while(1 == 1) {
		(void)printf("Enter resistance, or a non number to quit: ");
		(void)fgets(input, sizeof(input), stdin);
		result = sscanf(input, "%f", &resistance);

		if (result != 1) {
			break;
		}

		inv_resistance += 1.0 / resistance;
	}

	(void)printf("Total resistance is %f.\n", 1.0 / inv_resistance);
	return 0;
}
