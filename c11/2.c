/*
 * =============================================================================
 *
 *       Filename:  2.c
 *
 *    Description:  Define a struct for datetime.
 *
 *    		    I did more for the second part: instead of Creating a
 *    		    function to tell time difference, in minutes, of two times,
 *    		    I created a function to tell the time difference of two
 *    		    datetimes.  Function is called diff_in_minutes.
 *
 * 		    To build: gcc -o2 2.c datetime.c -I -Wall
 *
 *        Version:  1.0
 *        Created:  11-12-18 06:07:35 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan Kydd (), akydd@ualberta.net
 *        Company:  
 *
 * =============================================================================
 */
#include <stdio.h>
#include "datetime.h"

int main(void)
{
	struct datetime *a = create_datetime(2011, 12, 19, 23, 16 );
	struct datetime *b = create_datetime( 2010, 12, 19, 23, 16 );
	struct datetime *c = create_datetime( 2011, 12, 20, 23, 16 );
	struct datetime *d = create_datetime( 2011, 12, 20, 22, 16 );
	struct datetime *e = create_datetime( 2012, 12, 20, 22, 16 );

	(void)printf("Test for same date.\n");
	(void)printf("Minutes diff is %d.\n", diff_in_minutes(a, a));

	(void)printf("Test for day difference.\n");
	(void)printf("Minutes diff is %d.\n", diff_in_minutes(a, c));
	(void)printf("Other way is %d.\n", diff_in_minutes(c, a));

	(void)printf("Test for year difference.\n");
	(void)printf("Minutes diff is %d.\n", diff_in_minutes(a, b));
	(void)printf("Other way is %d.\n", diff_in_minutes(b, a));

	(void)printf("Test for hour difference.\n");
	(void)printf("Minutes diff is %d.\n", diff_in_minutes(c, d));
	(void)printf("Other way is %d.\n", diff_in_minutes(d, c));

	(void)printf("Test year diff with a leap year:\n");
	(void)printf("Minutes diff is %d.\n", diff_in_minutes(d, e));
	(void)printf("An extra day would add %d minutes.\n", 24*60);

	/* free memory */
	free_datetime(a);
	free_datetime(b);
	free_datetime(c);
	free_datetime(d);

	return 0;
}
