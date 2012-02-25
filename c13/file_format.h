/*
 * =============================================================================
 *
 *       Filename:  file_format.h
 *
 *    Description:  Defines binary file format for storing mailing labels
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

struct record {
	char first_name[30];
	char last_name[30];
	char street1[50];
	char street2[50];
	char municipality[50];
	char country[50];
	char province[50];
	char postal_code[10];
};

