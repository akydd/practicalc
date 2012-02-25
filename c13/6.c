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

static void usage(void);
static void write_test_data(char*);
static void get_mailing_labels(char*);
static void print_label(struct record);

int main(int argc, char *argv[])
{
	char *filename = argv[1];

	write_test_data(filename);
	get_mailing_labels(filename);

	return 0;
}

void usage()
{
	(void)printf("Use this program properly!\n");
	exit(EXIT_FAILURE);
}

void get_mailing_labels(char *filename)
{
	FILE *file;
	file = fopen(filename, "r");
	struct header file_header;
	struct record file_record;
	int items_read;
	int i;

	if (file == NULL) {
		(void)printf("Could not open data file!\n");
		usage();
	}

	/* read the file header */
	if ((items_read = 
		fread(&file_header, 1, sizeof(struct header), file)) != 0) {
		/* validate header */
		if (strcmp(file_header.type, "Mail") != 0 ) {
			(void)printf("Invalid file format!\n");
			(void)printf("File type is %s.\n", file_header.type);
			usage();
		} else {
			(void)printf("Num records is %d.\n",
					file_header.num_records);
		}

		/* if we're here, header validation passed. */
		/* file position is auto set at point after the header */
		for (i = 0; i < file_header.num_records; i++) {
			(void)fread(&file_record,
					1, sizeof(struct record), file);
			print_label(file_record);
		}
	} 

	(void)fclose(file);
}

void print_label(struct record rec)
{
	(void)printf("+\n");
	(void)printf("| %s %s\n", rec.first_name, rec.last_name);
	(void)printf("| %s\n", rec.street1);
	(void)printf("| %s\n", rec.street2);
	(void)printf("| %s %s  %s\n",
			rec.municipality, rec.province, rec.postal_code);
	(void)printf("| %s\n", rec.country);
	(void)printf("+\n\n");
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
