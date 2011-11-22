/*
 * =============================================================================
 *
 *       Filename:  4.c
 *
 *    Description:  Test is_hex(x) macro
 *
 *        Version:  1.0
 *        Created:  11-11-21 09:03:06 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan Kydd (), akydd@ualberta.net
 *        Company:  
 *
 * =============================================================================
 */
#include <stdio.h>
#include "boolean.h"

int main(void)
{
	int i;

	char valid_lower[] = {'a', 'b', 'c', 'd', 'e', 'f'};
	char valid_upper[] = {'A', 'B', 'C', 'D', 'E', 'F'};
	char invalid_chars[] = {'g', 'G', 'x', 'X', 'z', 'Z'};
	char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

	for(i = 0; i < 6; i++) {
		if (is_hex(valid_lower[i]) != TRUE) {
			(void)printf("Incorrect for [a-f].\n");
			break;
		}

		if (is_hex(valid_upper[i]) != TRUE) {
			(void)printf("Incorrect for [A-F].\n");
			break;
		}

		if (is_hex(invalid_chars[i]) != FALSE) {
			(void)printf("Incorrect for ^[a-fA-F].\n");
			break;
		}
	}

	for (i = 0; i < 9; i++) {
		if (is_hex(digits[i]) != TRUE) {
			(void)printf("Incorrect for [0-9].\n");
			break;
		}
	}

	return 0;
}
