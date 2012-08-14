/*
 * ============================================================================
 *
 *       Filename:  page_formatter.c
 *
 *    Description:  Page formatter module impl
 *
 *        Version:  1.0
 *        Created:  12-08-13 08:19:09 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan Kydd (), akydd@ualberta.net
 *        Company:  
 *
 * ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "page_formatter.h"

FILE *in_file;
char buffer[BUFFER_SIZE];

void open_file(char *filename)
{
	in_file = fopen(filename, "a+");
	if (in_file == NULL) {
		exit(EXIT_FAILURE);
	}

	/* read file into buffer */
	(void)fread(buffer, sizeof(char), BUFFER_SIZE, in_file);

	(void)fseek(in_file, 0, SEEK_SET);
}

void define_header(char *header)
{

}

void print_line(char *string)
{

}

void close_file(void)
{
	int status;
	status = fclose(in_file);
	if (status != 0) {
		exit(EXIT_FAILURE);
	}
}
