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
 *    		    diff_in_minutes should always return non-negative int,
 *    		    but it has a bug!
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

struct datetime {
	int year;
	int month;
	int day;
	int hour;
	int minute;
};

int days_per_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

static int diff_in_minutes(struct datetime, struct datetime);
static int minutes_between_years(struct datetime, struct datetime);
static int minutes_in_year(struct datetime);
static int is_leap_year(int);

int diff_in_minutes(struct datetime a, struct datetime b)
{
	int minutes = 0;

	if (a.year > b.year) {
		/* formula for total minutes is
		 * sum of total minutes in all years from start year to end year-1
		 *  + minutes in end year
		 *  - skipped minutes from beginning of start year
		 */
		minutes += minutes_between_years(a, b);
		minutes += minutes_in_year(a);
		minutes -= minutes_in_year(b);
	} else {
		minutes += minutes_between_years(b, a);
		minutes += minutes_in_year(b);
		minutes -= minutes_in_year(a);
	}

	return minutes;
}

int minutes_between_years(struct datetime a, struct datetime b)
{
	int days = 0;
	int i;

	for(i = b.year; i < a.year; i++) {
		if (is_leap_year(i)) {
			days += 366;
		} else {
			days += 365;
		}
	}
	return days * 24 * 60;
}

int minutes_in_year(struct datetime a)
{
	int days = 0;
	int i;

	for(i = 1; i < a.month; i++) {
		/* add extra day if it's february and a leap year */
		if (is_leap_year(a.year) && (i == 2)) {
			days += 29;
		} else {
			days += days_per_month[i - 1];
		}
	}

	/* add remaining days - 1 */ 
	days += (a.day - 1);

	/* all the minutes = minutes for days - 1
	 *  + hours & minutes for last day
	 */
	return (days * 24 * 60) + a.hour * 60 + a.minute;
}

int is_leap_year(int year)
{
	return 0;
}

int main(void)
{
	struct datetime a = { 2011, 12, 19, 23, 16 };
	struct datetime b = { 2010, 12, 19, 23, 16 };
	struct datetime c = { 2011, 12, 20, 23, 16 };
	struct datetime d = { 2011, 12, 20, 22, 16 };

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

	return 0;
}
