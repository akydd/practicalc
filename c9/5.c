/*
 * =============================================================================
 *
 *       Filename:  5.c
 *
 *    Description:  Test swap(x, y) macro. Does not use a tmp var! :)
 *
 *        Version:  1.0
 *        Created:  11-11-21 09:27:12 PM
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
	int a = 123;
	int b = 6;

	(void)printf("a is %d, b is %d.\n", a, b);
	swap(a, b);
	(void)printf("a is now %d, b is now %d.\n", a, b);

	return 0;
}
