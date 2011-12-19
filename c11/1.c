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

struct profile profile_list[MAX_RECORDS - 1];

static int profilecmp(const void *, const void *);
static void print_profiles(void);

/*
 * Sort profiles based on last name, then first name, then address1.
 */
int profilecmp(const void *a, const void *b)
{
	struct profile *ia = (struct profile *)a;
	struct profile *ib = (struct profile *)b;

	/* try the last name */
	int cmp = strcmp((*ia).lname, (*ib).lname);

	if (cmp == 0) {
		/* if last names are equal, try first name */
		cmp = strcmp((*ia).fname, (*ib).fname);
		if (cmp == 0) {
			/* still no luck?  Try address. */
			cmp = strcmp((*ia).address1, (*ib).address2);
		}
	}

	return cmp;
}

void print_profiles(void)
{
	int i;
	for (i = 0; i < MAX_RECORDS; i++) {
		(void)printf("First Name: %s\n", profile_list[i].fname);
		(void)printf("Last Name: %s\n", profile_list[i].lname);
		(void)printf("Address1: %s\n", profile_list[i].address1);

		if (strlen(profile_list[i].address2) > 0) {
			(void)printf("Address2: %s\n",
					profile_list[i].address2);
		}

		(void)printf("City: %s\n", profile_list[i].city);
		(void)printf("Province: %s\n", profile_list[i].province);
		(void)printf("Postal Code: %s\n", profile_list[i].postal_code);
		(void)printf("===============================\n\n");
	}
}

int main(void)
{
	/* here are some profile records */
	strcpy(profile_list[0].fname, "Mrs");
	strcpy(profile_list[0].lname, "Kydd");
	strcpy(profile_list[0].address1, "1428-330 Fake Street");
	strcpy(profile_list[0].city, "Edmonton");
	strcpy(profile_list[0].province, "Alberta");
	strcpy(profile_list[0].postal_code, "A1B2C3");

	strcpy(profile_list[1].fname, "Mr");
	strcpy(profile_list[1].lname, "Kydd");
	strcpy(profile_list[1].address1, "94 Fake Street");
	strcpy(profile_list[1].city, "Edmonton");
	strcpy(profile_list[1].province, "Alberta");
	strcpy(profile_list[1].postal_code, "A1B2C3");
	
	strcpy(profile_list[2].fname, "Mr");
	strcpy(profile_list[2].lname, "Kydd");
	strcpy(profile_list[2].address1,"43 Fake Street");
	strcpy(profile_list[2].city, "Sherwood Park");
	strcpy(profile_list[2].province, "Alberta");
	strcpy(profile_list[2].postal_code, "D4E5F6");

	strcpy(profile_list[3].fname, "Leeroy");
	strcpy(profile_list[3].lname, "Jenkins");
	strcpy(profile_list[3].address1,"1943 Fake Avenue");
	strcpy(profile_list[3].address2, "Apt 123");
	strcpy(profile_list[3].city, "Sherwood Park");
	strcpy(profile_list[3].province, "Alberta");
	strcpy(profile_list[3].postal_code, "D4E5F6");

	/* sort the profiles */
	(void)qsort(&profile_list, MAX_RECORDS, sizeof(struct profile),
			profilecmp);

	/* print them out! */
	(void)print_profiles();

	return 0;
}
