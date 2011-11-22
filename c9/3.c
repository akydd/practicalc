/*
 * =============================================================================
 *
 *       Filename:  3.c
 *
 *    Description:  Test the is_digit(x) macro
 *
 *        Version:  1.0
 *        Created:  11-11-21 08:34:32 PM
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

int main(void) {
	
	int a = 0;
	char x = 'x';
	char y = '5';

	if (is_digit(a) == FALSE) {
		(void)printf("0 okay.\n");
	}
	if (is_digit(x) == FALSE) {
		(void)printf("\'x\' okay.\n");
	}
	if (is_digit(y) == TRUE) {
		(void)printf("\'5\' okay.\n");
	}

	return 0;
}
