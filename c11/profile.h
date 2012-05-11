/*
 * =============================================================================
 *
 *       Filename:  profile.h
 *
 *    Description:  Header for struct profile functions.
 *
 *        Version:  1.0
 *        Created:  12-05-10 09:00:13 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan Kydd (), akydd@ualberta.net
 *        Company:  
 *
 * =============================================================================
 */

struct profile {
	char fname[60];
	char lname[60];
	char address1[60];
	char address2[60];
	char city[60];
	char province[60];
	char postal_code[7];
};

/* 
 * Compare two struct profiles
 */
int profilecmp(const void *, const void *);

/*
 * Print a struct profile
 */
void print_profile(const struct profile *);

/* 
 * Create a struct profile
 */
struct profile *create_profile(char *, char *, char*, char*,
		char*, char*, char*);

/* 
 * destroy a struct profile
 */
void free_profile(struct profile *);

