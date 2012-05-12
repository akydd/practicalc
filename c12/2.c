/*
 * =============================================================================
 *
 *       Filename:  2.c
 *
 *    Description:  Write a function that takes a single string as its
 *                  argument and returns a pointer to the first non-white
 *                  char in the string.  Returns NULL if no such char is found.
 *
 *                  There are probably memory leaks in this.  Splint complains!
 *
 *        Version:  1.0
 *        Created:  11-12-27 03:58:32 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan Kydd (), akydd@ualberta.net
 *        Company:  
 *
 * =============================================================================
 */
#include <stdio.h>
#include <ctype.h>

static char *find_nonwhite_char(char *p)
{
	while (*p != '\0') {
		/* use isspace(int) */
		if (isspace((int)*p) == 0) {
			return p;
		}
		p++;
	}
	return NULL;
}

int main(void)
{
	char line[80];
	char *q;
	(void)printf("Enter a string: ");
	(void)fgets(line, sizeof(line), stdin);
	q = find_nonwhite_char(line);

	if (q != NULL) {
		(void)printf("The first nonwhite character is %c.\n", *q);
	} else {
		(void)printf("No nonwhite char found.\n");
	}
	return 0;
}
