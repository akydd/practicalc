/*
 * =============================================================================
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
 * =============================================================================
 */
#include <stdio.h>

static int wordcount(char*);
static int char_is_alpha(char);
static int char_is_whitespace(char);

int char_is_whitespace(char letter)
{
	int is_whitespace = 0;

	if ( (letter == ' ') || (letter == '\t') || (letter == '\n') ) {
		is_whitespace = 1;
	}
	return is_whitespace;
}

int char_is_alpha(char letter)
{
	int is_char = 0;

	if ( ( ((int)letter <= 90) && ((int)letter >= 65) ) ||
		( ((int)letter <= 122) && ((int)letter >= 97) ) ) {
		is_char = 1;
	}
	return is_char;
}

int wordcount(char *string)
{
	int count = 0;
	char *str_ptr = string;
	char *srch_ptr = str_ptr + 1;
	char *parse_ptr;
	int increment = 1;

	while (*str_ptr != '\0') {

		/* skip leading whitespace */
		while (char_is_whitespace(*str_ptr) == 1) {
			str_ptr++;
		}

		/* find the 1st non whitespace char */
		if (char_is_whitespace(*str_ptr) == 0) {
			/* then find the next whitespace, or \0 */
			srch_ptr = str_ptr + 1;
			while ( (*srch_ptr != '\0') && 
					(char_is_whitespace(*srch_ptr) == 0) ) {
				srch_ptr++;
			}

			/* check all chars between the two ptrs */
			for (parse_ptr = str_ptr; parse_ptr < srch_ptr;
					parse_ptr++) {
				/* if char is not alpha, don't increment
				 * count, and forget about the other chars */
				if (char_is_alpha(*parse_ptr) == 0) {
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
