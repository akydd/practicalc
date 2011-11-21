/*
 * =============================================================================
 *
 *       Filename:  6.c
 *
 *    Description:  'replace' replaces all "-" with "_" in char array.
 *
 *        Version:  1.0
 *        Created:  11-11-20 07:34:23 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan Kydd (), akydd@ualberta.net
 *        Company:  
 *
 * =============================================================================
 */
#include <stdio.h>

static void replace(char*);

void replace(char *string)
{
	while (*string != '\0') {
		if (*string == '-') {
			*string = '_';
		}
		string++;
	}
}

int main(void)
{
	/* lets tests this! */
	char string1[] = "I-have-lots-of-hyphens!";
	char string2[] = "No hyphens here.";

	(void)printf("Before: \"%s\"\n", string1);
	replace(string1);
	(void)printf("After: \"%s\"\n", string1);

	(void)printf("Before: \"%s\"\n", string2);
	replace(string2);
	(void)printf("After: \"%s\"\n", string2);

	return 0;
}
