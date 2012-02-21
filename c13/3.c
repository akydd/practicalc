/*
 * =============================================================================
 *
 *       Filename:  3.c
 *
 *    Description:  Reads a file containing list of numbers, one per line,
 *    		    then writes two files, one with all numbers divisble by 3,
 *    		    the second with all other numbers.
 *
 *        Version:  1.0
 *        Created:  12-01-11 09:08:42 PM
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
void parse(FILE*, FILE*, FILE*);

char *program_name;

int main(int argc, char* argv[])
{
	program_name = argv[0];
	char *input_file_name = argv[1];
	char *div_3_file_name= argv[2];
	char *other_file_name = argv[3];

	/* open all files */
	FILE *in_file = fopen(input_file_name, "r");
	FILE *div_3_file = fopen(div_3_file_name, "w");
	FILE *other_file = fopen(other_file_name, "w");
	
	/* check all files */
	if (in_file == NULL) {
		(void)printf("Cannot open input file!\n");
		(void)usage();
	}
	if (div_3_file == NULL) {
		(void)printf("Cannot open [div3]!\n");
		(void)usage();
	}
	if (other_file == NULL) {
		(void)printf("Cannot open [other]!\n");
		(void)usage();
	}

	/* read input */
	(void)parse(in_file, div_3_file, other_file);

	/* close all files */
	(void)fclose(other_file);
	(void)fclose(div_3_file);
	(void)fclose(in_file);
	return 0;
}

void parse(FILE *in_file, FILE *div_3_file, FILE *other_file)
{
	/* vars for storing input data */
	char *input;
	char input_array[100];
	int the_number;
	int scan_count;

	/* parse input, one line at a time */
	while (1 == 1) {
		input = fgets(input_array, sizeof(input_array), in_file);
		/* break on eof */
		if (input == NULL) {
			break;
		}

		/* try to convert input to an int */
		scan_count = sscanf(input_array, "%d", &the_number);

		/* output as appropriate, one num per line */
		if (scan_count == 1) {
			if (the_number % 3 == 0) {
				(void)fprintf(div_3_file, "%d\n", the_number);
			} else {
				(void)fprintf(other_file, "%d\n", the_number);
			}
		}
	}
}

void usage(void)
{
	(void)printf("Usage: %s ", program_name);
	(void)printf("[inputfile] [div3] [other]\n");
	(void)printf("where [div3] contains numbers divisible by 3, and ");
	(void)printf("[other] contains all other numbers.\n");
	exit(8);
}
