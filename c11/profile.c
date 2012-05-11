/*
 * =============================================================================
 *
 *       Filename:  profile.c
 *
 *    Description:  profile.h implementation
 *
 *        Version:  1.0
 *        Created:  12-05-10 09:04:23 PM
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
#include "profile.h"

/*
 * Create a new struct profile and return ptr to it
 */
struct profile *create_profile(char *fname, char *lname, char *address1,
		char *address2, char *city, char *province, char *postal)
{
	struct profile *the_profile = malloc(sizeof(struct profile));

	if (the_profile != NULL) {	
		strncpy(the_profile->fname, fname, 60);
		strncpy(the_profile->lname, lname, 60);
		strncpy(the_profile->address1, address1, 60);
		strncpy(the_profile->address2, address2, 60);
		strncpy(the_profile->city, city, 60);
		strncpy(the_profile->province, province, 60);
		strncpy(the_profile->postal_code, postal, 7);
	}

	/*@null@*/
	return the_profile;
}


/* 
 * free allocated memory for the struct profile
 */
void free_profile(struct profile *the_profile)
{
	free(the_profile);
}	


/*
 * Sort profiles based on last name, then first name, then address1.
 */
int profilecmp(const void *a, const void *b)
{
	struct profile **ia = (struct profile **)a;
	struct profile **ib = (struct profile **)b;

	/* try the last name */
	int cmp = strcmp((**ia).lname, (**ib).lname);

	if (cmp == 0) {
		/* if last names are equal, try first name */
		cmp = strcmp((**ia).fname, (**ib).fname);
		if (cmp == 0) {
			/* still no luck?  Try address. */
			cmp = strcmp((**ia).address1, (**ib).address2);
		}
	}

	return cmp;
}


/* 
 * print a struct profile *
 */
void print_profile(const struct profile *the_profile)
{
	(void)printf("First Name: %s\n", the_profile->fname);
	(void)printf("Last Name: %s\n", the_profile->lname);
	(void)printf("Address1: %s\n", the_profile->address1);

	if (strlen(the_profile->address2) > 0) {
		(void)printf("Address2: %s\n",
			the_profile->address2);
	}

	(void)printf("City: %s\n", the_profile->city);
	(void)printf("Province: %s\n", the_profile->province);
	(void)printf("Postal Code: %s\n", the_profile->postal_code);
	(void)printf("===============================\n\n");
}

