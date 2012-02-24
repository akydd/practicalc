/*
 * =============================================================================
 *
 *       Filename:  4a.c
 *
 *    Description:  Reads an ASCII file containing numbers and writes them to a
 *    		    binary file.
 *
 *        Version:  1.0
 *        Created:  12-02-23 09:23:03 PM
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

void usage(void);

int main (int argc, char *argv[])
{
	char *in_filename = argv[1];
	char *out_filename = argv[2];

	FILE *in_file;
	FILE *out_file;

	char buffer[100];
	int number;

	/* open files */
	in_file = fopen(in_filename, "r");
	out_file = fopen(out_filename, "w");

	/* check for void files */
	if (in_file == NULL) {
		(void)printf("Could not open input file.\n");
		usage();
	}
	if (out_file == NULL) {
		(void)printf("Could not open output file.\n");
		usage();
	}

	/* read as ASCII, write as binary */
	while (fgets(buffer, sizeof(buffer), in_file) != NULL) {
		if (sscanf(buffer, "%d", &number) == 1) {
			fwrite(&number, 1, sizeof(int), out_file);
		}
	}

	(void)fclose(out_file);
	(void)fclose(in_file);
	return 0;
}

void usage()
{
	(void)printf("Use it properly!\n");
	exit(8);
}
