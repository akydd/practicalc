/*
 * ============================================================================
 *
 *       Filename:  search_open.h
 *
 *    Description:  Given an array of filenames, search until existing one is
 *    		    found, then open it.
 *
 *        Version:  1.0
 *        Created:  12-09-10 08:18:09 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan Kydd
 *   Organization:  
 *
 * ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

FILE *th_file;

void search_files(int, char **);
