/*
 * ============================================================================
 *
 *       Filename:  2.c
 *
 *    Description:  Test for search_open module
 *
 *        Version:  1.0
 *        Created:  12-09-10 08:49:13 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan Kydd (), akydd@ualberta.net
 *   Organization:  
 *
 * ============================================================================
 */
#include <stdlib.h>
#include "search_open.h"

int main(int argc, char **argv)
{
	if (argc < 2) {
		(void)printf("You didn't enter any filenames!\n");
	} else {
		/* decrement arg count and skip the first arg */
		search_files(--argc, ++argv);
	}

	exit(EXIT_SUCCESS);
}
