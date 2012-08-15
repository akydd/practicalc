/*
 * =============================================================================
 *
 *       Filename:  5.c
 *
 *    Description:  Copies a file, removing all characters with the high bit
 *    		    set.  Tough to test, as all ASCII chars do not have the
 *    		    high bit set.
 *    
 *
 *        Version:  1.0
 *        Created:  12-02-24 08:44:09 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan Kydd (), akydd@ualberta.net
 *        Company:  
 *
 * =============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

static void usage(void);

int main(int argc, char *argv[])
{
	if (argc != 3) {
		usage();
	}

	char *in_filename = argv[1];
	char *out_filename = argv[2];

	FILE *in_file;
	FILE *out_file;

	int ch;

	in_file = fopen(in_filename, "r");
	out_file = fopen(out_filename, "w");

	/* check if files open ok */
	if (in_file == NULL) {
		(void)printf("Could not open input file!\n");
		usage();
	}
	if (out_file == NULL) {
		(void)printf("Could not open output file!\n");
		usage();
	}

	/* read input file, 1 char at a time */
	while ((ch = fgetc(in_file)) != EOF) {
		/* if high bit is not set, write to output file */
		if ((ch & 0x80) == 0) {
			(void)fputc(ch, out_file);
		}
	}

	/* close files */
	(void)fclose(out_file);
	(void)fclose(in_file);

	return 0;
}

void usage()
{
	(void)printf("Use this program properly!\n");
	exit(EXIT_FAILURE);
}
