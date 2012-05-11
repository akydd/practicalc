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

#include "profile.h"

#define MAX_RECORDS 4

struct profile *profile_list[MAX_RECORDS];

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
