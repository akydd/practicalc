/*
 * =============================================================================
 *
 *       Filename:  4.c
 *
 *    Description:  hash function sums all dec values of chars in string.
 *
 *        Version:  1.0
 *        Created:  11-11-20 06:54:06 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan Kydd (), akydd@ualberta.net
 *        Company:  
 *
 * =============================================================================
 */
#include <stdio.h>

static int hash(char*);

int hash(char *string)
{
	int sum = 0;

	while (*string != '\0') {
		sum += (int)*string;
		string++;
	}
	return sum;
}

int main(void)
{
	/* lets test this! */
	char string1[] = "aA";
	char string2[] = "abcdefghijklmnopqrstuvwxyz";

	(void)printf("Hash of \"%s\" should be %d.  It is %d.\n",
			string1, 65 + 97, hash(string1));
	(void)printf("Hash of \"%s\" should be %d.  It is %d.\n",
		string2, 26 * (97 + 122) / 2, hash(string2));

	return 0;
}
