/*
 * =============================================================================
 *
 *       Filename:  2.c
 *
 *    Description:  function begins(string1, string2) returns true if string1
 *    		    begins string2. Takes newlines into account.
 *
 *        Version:  2.0
 *        Created:  11-11-20 03:12:16 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan Kydd (), akydd@ualberta.net
 *        Company:  
 *
 * =============================================================================
 */
#include <stdio.h>
#include <string.h>

static int begins(char*, char*);

int begins(char *string1, char *string2)
{
	while(1 == 1) {
		/* Handles two cases:
		 * 1. empty string1 always begins string2
		 * 2. if we've made it to the end of string1 without exiting, then
		 *    string1 must have matched string2. */
		if (*string1 == '\0') {
			return 1;
		}

		/* Handles two cases:
		 * 1. some letter in string1 does not match to string2
		 * 2. string2 is shorter than string1 */
		if (*string1 != *string2) {
			return 0;
		}

		/* If we get here, move on to the next char */
		string1++;
		string2++;
	}
}

int main(void)
{
	char input1[100];
	char input2[100];
	int test_begins;

	(void)printf("Enter string1: ");
	(void)fgets(input1, sizeof(input1), stdin);
	(void)printf("Enter string2: ");
	(void)fgets(input2, sizeof(input2), stdin);

	/* chop off the newlines */
	input1[strlen(input1)-1] = '\0';
	input2[strlen(input2)-1] = '\0';

	/* test the 'begins' function */
	test_begins = begins(input1, input2);

	if (test_begins == 1) {
		(void)printf("\"%s\" begins \"%s\".\n", input1, input2);
	} else {
		(void)printf("\"%s\" does not begin \"%s\".\n", input1, input2);
	}

	return 0;
}
