/*
 * ============================================================================
 *
 *       Filename:  1.c
 *
 *    Description:  wordcount counts the # of words in a string.
 *    		    I defined a word using the POSIX character class:
 *    		    [A-Za-z0-9_]
 *
 *        Version:  1.0
 *        Created:  11-11-20 10:18:26 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan Kydd (), akydd@ualberta.net
 *        Company:  
 *
 * ============================================================================
 */
#include <stdio.h>
#include <ctype.h>

static int wordcount(char*);
static int isword(char);

int isword(char character)
{
	if ((isalnum((int)character) != 0) || (character == '_')) {
		return 1;
	} else {
		return 0;
	}
}

int wordcount(char *string)
{
	int count = 0;
	char *str_ptr = string;
	int is_previous_word = 0;

	while (*str_ptr != '\0') {
		if(isword(*str_ptr) != 0) {
			if(is_previous_word == 0) {
				count++;
			}
			is_previous_word = 1;
		} else {
			is_previous_word = 0;
		}
		str_ptr++;
	}
	return count;
}

int main(void)
{
	char input[200];
	int count;

	(void)printf("Enter string: ");
	(void)fgets(input, sizeof(input), stdin);

	count = wordcount(input);
	(void)printf("There are %d words in \"%s\".\n", count, input);

	return 0;
}
