/*
 * =============================================================================
 *
 *       Filename:  4b.c
 *
 *    Description:  Converts a binary file of numbers to an ASCII file
 *
 *        Version:  1.0
 *        Created:  12-02-24 07:50:14 PM
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

	int number;

       	in_file = fopen(in_filename, "r");
	out_file = fopen(out_filename, "w");

	/* did files open ok? */
	if (in_file == NULL) {
		(void)printf("Could not open input file!\n");
		usage();
	}
	if (out_file == NULL) {
		(void)printf("Could not open output file!\n");
		usage();
	}

	while (fread(&number, sizeof(int), 1, in_file) != 0) {
		(void)fprintf(out_file, "%d\n", number);
	}

	/* close all files */
	(void)fclose(out_file);
	(void)fclose(in_file);

	return 0;
}

void usage()
{
	(void)printf("Use this program properly!\n");
	exit(EXIT_FAILURE);
}
