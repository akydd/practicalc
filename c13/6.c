/*
 * =============================================================================
 *
 *       Filename:  6.c
 *
 *    Description:  Read (and write) to binary file as defined in file_format.h.
 *    		    Produce a set of mailing labels from the data.
 *    		    Could be improved by checking feof and/or ferror.
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
#include <string.h>
#include "file_format.h"
#include "../c11/profile.h"

static void usage(void);
static void write_test_data(char *);
static void get_mailing_labels(char *);

int main(int argc, char *argv[])
{
	if (argc != 2) {
		usage();
	}

	char *filename = argv[1];

	write_test_data(filename);
	get_mailing_labels(filename);

	return 0;
}

void usage()
{
	(void) printf("Use this program properly!\n");
	exit(EXIT_FAILURE);
}

void get_mailing_labels(char *filename)
{
	FILE *file;
	file = fopen(filename, "r");
	struct header *file_header;
	struct profile *file_record;
	int items_read;
	int i;

	if (file == NULL) {
		(void) printf("Could not open data file!\n");
		usage();
	}

	/* read the file header */
	if ((items_read =
	     fread(file_header, sizeof(struct header), 1, file)) != 0) {
		/* validate header */
		if (strcmp(file_header->type, "Mail") != 0) {
			(void) printf("Invalid file format!\n");
			(void) printf("File type is %s.\n",
				      file_header->type);
			usage();
		} else {
			(void) printf("Num records is %d.\n",
				      file_header->num_records);
		}

		/* if we're here, header validation passed. */
		/* file position is auto set at point after the header */
		for (i = 0; i < file_header->num_records; i++) {
			(void) fread(file_record,
				     sizeof(struct profile), 1, file);
			print_profile(file_record);
		}
	}

	(void) fclose(file);
}

void write_test_data(char *filename)
{
	FILE *file;
	file = fopen(filename, "w");

	if (file == NULL) {
		(void) printf("Could not write test data!\n");
		usage();
	}

	/* define the header and write to file */
	struct header *file_header = create_header("Mail", 1, 2);
	(void) fwrite(file_header, sizeof(struct header), 1, file);

	/* define records and write to file */
	struct profile *record_1 = create_profile("Alan", "Kydd", "Unit 1824",
			"123 Fake Street", "Edmonton", "Alberta", "T0C0C0");
	struct profile *record_2 = create_profile("Bruce", "Wayne",
			"Wayne Manor", "", "Gotham City", "New York",
			"123345");
	(void) fwrite(record_1, sizeof(struct profile), 1, file);
	(void) fwrite(record_2, sizeof(struct profile), 1, file);

	/* close file */
	(void) fclose(file);
	/* free allocated mem */
	free(file_header);
	free(record_1);
	free(record_2);
}
