/*
 * =============================================================================
 *
 *       Filename:  2.c
 *
 *    Description:  Test is_div_10(x) macro.
 *
 *        Version:  1.0
 *        Created:  11-11-21 07:55:05 PM
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
	int a = 20;
	int b = 2;

	if ( (is_div_10(a) == TRUE) && (is_div_10(b) == FALSE) ) {
		(void)printf("is_div_10(x) is working properly.\n");
	}

	return 0;
}

