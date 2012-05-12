/*
 * =============================================================================
 *
 *       Filename:  file_format.c
 *
 *    Description:  Implementation of file_format.h
 *
 *        Version:  1.0
 *        Created:  12-05-12 08:57:36 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan Kydd (), akydd@ualberta.net
 *        Company:  
 *
 * =============================================================================
 */

#include <stdlib.h>
#include <string.h>
#include "file_format.h"

struct header *create_header(const char* type, const int version,
		const int num_records)
{
	struct header *new_header = malloc(sizeof(struct header));

	if (new_header != NULL) {
		strncpy(new_header->type, type, 5);
		new_header->version = version;
		new_header->num_records = num_records;
	} else {
		exit(EXIT_FAILURE);
	}

	return new_header;
}
