/*
 * =============================================================================
 *
 *       Filename:  6.c
 *
 *    Description:  Read (and write) to binary file as defined in file_format.h.
 *    		    Produce a set of mailing labels from the data.
 *
 *        Version:  1.0
 *        Created:  12-02-24 11:31:46 PM
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
#include "file_format.h"

static void usage(void);
static void write_test_data(char*);

int main(int argc, char *argv[])
{
	char *filename = argv[1];

	write_test_data(filename);
	//get_mailing_labels(file);

	return 0;
}

void usage()
{
	(void)printf("Use this program properly!\n");
	exit(EXIT_FAILURE);
}

void write_test_data(char *filename)
{
	FILE *file;
	file = fopen(filename, "w");

	if (file == NULL) {
		(void)printf("Could not write test data!\n");
		usage();
	}

	/* define the header and write to file */
	struct header file_header = {
		"Mail",
		1,
		2
	};
	(void)fwrite(&file_header, 1, sizeof(struct header), file);

	/* define a record and write to file */
	struct record record_1 = {
		"Alan",
		"Kydd",
		"Unit 1824",
		"123 Fake Street",
		"Edmonton",
		"Canada",
		"Alberta",
		"T0C0C0"
	};
	(void)fwrite(&record_1, 1, sizeof(struct record), file);


	/* define another record and write to file */
	struct record record_2 = {
		"Bruce",
		"Wayne",
		"Wayne Manor",
		"",
		"Gotham City",
		"USA",
		"New York",
		"123345"
	};
	(void)fwrite(&record_2, 1, sizeof(struct record), file);

	/* close file */
	(void)fclose(file);
}
