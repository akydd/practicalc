/*
 * =============================================================================
 *
 *       Filename:  file_format.h
 *
 *    Description:  Defines binary file format for storing mailing labels.
 *    		    struct header is the file header.
 *    		    struct profile, from previous exercises, will be used to
 *    		    store person data.
 *		    
 *        Version:  1.0
 *        Created:  12-02-24 11:03:09 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan Kydd (), akydd@ualberta.net
 *        Company:  
 *
 * =============================================================================
 */


struct header {
	char type[5];
	int version;
	int num_records;
};

struct header *create_header(const char *, const int, const int);
