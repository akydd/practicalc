/*
 * =============================================================================
 *
 *       Filename:  5.c
 *
 *    Description:  Print out the multiplication tables
 *
 *        Version:  1.0
 *        Created:  11-11-09 10:02:20 PM
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
	int i;
	int j;

	for(i = 1; i < 13; i ++) {
		for(j = 1; j < 13; j++) {
			(void)printf("%2d x %2d = %3d\n", i, j, i*j);
		}
	}
	return 0;
}
