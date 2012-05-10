/*
 * =============================================================================
 *
 *       Filename:  1.c
 *
 *    Description:  Take a list of names and addresses, sort and print them
 *    		    as mailing labels.
 *
 *    		    This is pretty basic.  No txt file loading capabilities or
 *    		    input from stdin.
 *
 *        Version:  1.0
 *        Created:  11-12-03 08:36:40 PM
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

#define MAX_RECORDS 4


struct profile {
	char fname[60];
	char lname[60];
	char address1[60];
	char address2[60];
	char city[60];
	char province[60];
	char postal_code[7];
};

struct profile *profile_list[MAX_RECORDS - 1];

static int profilecmp(const void *, const void *);
static void print_profile(const struct profile *);
static struct profile *create_profile(char *, char *, char*, char*,
		char*, char*, char*);
static void free_profile(struct profile *);

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


int main(void)
{
	/* here are some profile records */
	profile_list[0] = create_profile("Mrs", "Kydd", "1428-330 Fake Street",
			"Unit 1428", "Edmonton", "Alberta", "A1B2C3");
	profile_list[1] = create_profile("Mr", "Kydd", "94 Fake Street",
			"Unit 505", "Edmonton", "Alberta", "A1B2C3");
	profile_list[2] = create_profile("Mr", "Kydd", "43 Fake Street",
			"Unit 227", "Sherwood Park", "Alberta", "D4E5F6");
	profile_list[3] = create_profile("Leeroy", "Jenkins",
			"1943 Fake Avenue", "Apt 123", "Sherwood Park",
			"Alberta", "D4E5F6");

	/* sort the profiles */
	(void)qsort(&profile_list, MAX_RECORDS, sizeof(struct profile *),
			profilecmp);
	
	/* print them out! */
	int i = 0;
	for(i = 0; i < MAX_RECORDS; i++) {
		(void)print_profile(profile_list[i]);
	}

	/* free memory */
	for(i = 0; i < MAX_RECORDS; i++) {
		(void)free_profile(profile_list[i]);
	}
	
	return 0;
}
