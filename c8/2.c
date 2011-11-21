/*
 * =============================================================================
 *
 *       Filename:  2.c
 *
 *    Description:  function begins(string1, string2) returns true if string1
 *    		    begins string2. Takes newlines into account.
 *
 *        Version:  1.0
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
	int ret_val = 1;
	char *str1_ptr = string1;
	char *str2_ptr = string2;

	if (strlen(string1) <= strlen(string2)) {
		while (*str1_ptr != '\0') {
			if (*str1_ptr != *str2_ptr) {
				ret_val = 0;
				break;
			}
			str1_ptr++;
			str2_ptr++;
		}
	} else {
		ret_val = 0;
	}

	return ret_val;
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
