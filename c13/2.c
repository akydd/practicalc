/*
 * =============================================================================
 *
 *       Filename:  2.c
 *
 *    Description:  Program copies a file and converts tabs to 4 spaces. 
 *                  Uses fputc, instead of trying to implement string
 *                  replace with strstr etc.
 *
 *        Version:  1.0
 *        Created:  12-01-09 08:56:00 PM
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

char *program_name;
void usage(void);

int main(int argc, char *argv[])
{
	program_name = argv[0];
	char *in_file_name = argv[1];
	char *out_file_name = argv[2];;

	FILE *in_file;
	FILE *out_file;

	int ch;
	char *spaces = "    ";

	if (argc != 3) {
		(void)usage();
	}

	in_file = fopen(in_file_name, "r");
	if (in_file == NULL) {
		(void)printf("Cannot open file %s.\n", in_file_name);
		(void)usage();
	}
	out_file = fopen(out_file_name, "w");
	if (out_file == NULL) {
		(void)printf("Cannot write to file %s.\n", out_file_name);
		(void)usage();
	}

	/* read, convert and write lines */
	while (1 == 1) {
		ch = fgetc(in_file);
		if (ch == EOF) {
			break;
		}
		if (ch == '\t') {
			(void)fputs(spaces, out_file);
		} else {
			(void)fputc(ch, out_file);
		}
	}

	(void)fclose(in_file);
	(void)fclose(out_file);
	return 0;
}

void usage(void)
{
	(void)printf("Usage is %s ", program_name);
	(void)printf("[input file] [output file]\n");
	exit(EXIT_FAILURE);
}
