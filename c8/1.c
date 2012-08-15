/*
 * ============================================================================
 *
 *       Filename:  1.c
 *
 *    Description:  wordcount counts the # of words in a string.
 *    		    I defined a word as a sequence of at least 1 chars,
 *    		    each having dec value in [65, 90] U [97, 122]. Words must
 *    		    be separated by whitespace or newline
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

int wordcount(char *string)
{
	int count = 0;
	char *str_ptr = string;
	char *srch_ptr = str_ptr + 1;
	char *parse_ptr;
	int increment = 1;

	while (*str_ptr != '\0') {

		/* skip leading whitespace */
		while ((isspace((int)*str_ptr)) != 0) {
			str_ptr++;
		}

		/* find the 1st non whitespace char */
		if (isspace((int)*str_ptr) == 0) {
			/* then find the next whitespace, or \0 */
			srch_ptr = str_ptr + 1;
			while ( (*srch_ptr != '\0') && 
					(isspace((int)*srch_ptr) == 0) ) {
				srch_ptr++;
			}

			/* check all chars between the two ptrs */
			for (parse_ptr = str_ptr; parse_ptr < srch_ptr;
					parse_ptr++) {
				/* if char is not alpha, don't increment
				 * count, and forget about the other chars */
				if(isalpha((int)*parse_ptr) == 0) {
					increment = 0;
					break;
				}
			}

			if (increment == 1) {
				count++;
			}
		}

		/* move str_ptr to trailing whitespace or \0 */
		str_ptr = srch_ptr;
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
