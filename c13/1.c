/*
 * =============================================================================
 *
 *       Filename:  1.c
 *
 *    Description:  Program reads a file and counts the number of lines in it.
 *
 *        Version:  1.0
 *        Created:  12-01-09 08:08:42 PM
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
	char *file_name = argv[1];
	FILE *in_file;
	int count = 0;
	char *str;
	char string[200];

	in_file = fopen(file_name, "r");
	if (in_file == NULL) {
		(void)printf("Cannot open file %s.\n", file_name);
		(void)usage();
	}

	/* read and count lines */
	while (1 == 1) {
		str = fgets(string, sizeof(string), in_file);
		if (str == NULL) {
			break;
		}
		(void)printf("Line %d: %s", count, str);
		count++;
	}

	(void)fclose(in_file);
	return 0;
}

void usage(void)
{
	(void)printf("Usage is %s [filename]\n", program_name);
	exit(EXIT_FAILURE);
}
