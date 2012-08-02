/*
 * =====================================================================================
 *
 *       Filename:  scan.c
 *
 *    Description:  Read in a text file and create a cross reference of all words
 *    		    contained within.
 *
 *        Version:  1.0
 *        Created:  7/31/2012 3:42:55 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan Kydd (), akydd@ualberta.net
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "cross_ref.h"

void usage();

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int main (int argc, char *argv[])
{
	FILE *in_file = NULL;
	struct tree_node *word_tree = NULL;
	char line_buffer[200];	/* stores each line from input file */
	char word_buffer[20];	/* stores each word, null terminated */
	char *word;		/* stores each word from the input file */
	int i = 0;		/* input file line counter.  Count starts at 1. */

	if (argc != 2) {
		usage();
		return EXIT_FAILURE;
	}

	/* try to open the text file */
	in_file = fopen(argv[1], "r");
	if (in_file == NULL) {
		(void)printf("Cannot open file!\n");
		usage();
		return EXIT_FAILURE;
	}

	/* read in file by line */
	while(fgets(line_buffer, sizeof(line_buffer), in_file) != NULL) {
		i++;
		/* process the words in the buffer */
		char *search_ptr = line_buffer;
		char *word_ptr = word_buffer;
		while (*search_ptr != '\0') {
			if(isalpha(*search_ptr) != 0) {
				*word_ptr = *search_ptr;
				word_ptr++;
				if(isalpha(*(search_ptr + 1)) == 0) {
					*word_ptr = '\0';
					insert(word_buffer, i, &word_tree);
					word_ptr = word_buffer;
				}
			}
			search_ptr++;
		}
	}
	(void)fclose(in_file);

	/* print out the reference */
	print_tree_node(word_tree);

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  usage
 *  Description:  print the usage of the routine
 * =====================================================================================
 */
void usage ()
{
	(void)printf("Usage:\n");
	(void)printf("scan <filename>");
}		/* -----  end of function usage  ----- */
