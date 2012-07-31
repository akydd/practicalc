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
#include "cross_ref.h"

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int main ( int argc, char *argv[] )
{
	FILE *in_file = NULL;
	struct tree_node **word_tree;
	char buffer[200];	/* stores each line from input file */
	char delimiter[] = " ";
	char *word;		/* stores each word from the input file */
	int i = 0;		/* input file line counter.  Count starts at 1. */

	if (argc != 2) {
		usage();
		return EXIT_FAILURE;
	}

	/* try to open the text file */
	in_file = fopen(argv[1], 'r');
	if (in_file == NULL) {
		(void)printf("Cannot open file!");
		usage();
		return EXIT_FAILURE;
	}

	/* read in file by line */
	while(fgets(buffer, sizeof(buffer), in_file) != NULL) {
		i++;
		/* process the words in the buffer */
		word = strtok(buffer, delimiter);
		while (word != NULL) {
			insert(word, i, word_tree);
			word = strtok(NULL, delimiter);
		}
	}
	(void)fclose(in_file);

	/* print out the reference */
	print_tree_node(&word_tree);

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
