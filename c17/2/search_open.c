/*
 * =============================================================================
 *
 *       Filename:  search_open.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12-09-10 08:37:02 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan Kydd (), akydd@ualberta.net
 *   Organization:  
 *
 * =============================================================================
 */
#include "search_open.h"

void search_files(int size, char **filenames)
{
	int i;
	for(i = 0; i < size; i++) {
		th_file = fopen(*(filenames + i), "r");

		/* check if open success */
		if (th_file != NULL) {
			(void)printf("File %s found!\n", *(filenames + i));
			break;
		}
	}

	if (th_file == NULL) {
		(void)printf("No file found.\n");
	} else {
		(void)printf("Closing file %s.\n", *(filenames + i));
		(void)fclose(th_file);
	}
}
