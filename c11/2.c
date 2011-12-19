/*
 * =============================================================================
 *
 *       Filename:  2.c
 *
 *    Description:  Define a struct for datetime.
 *    		    Create a function to tell time difference of two times,
 *    		    in minutes.
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
}

int days_per_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int datetime_diff_in_minutes(datetime a, datetime b)
{
	int minutes = 0;

	if (a.year > b.year) {
		minutes += days_for_year(a, b);
		minutes += days_for_month_and_day(a, b);
	} else {
		minutes += days_for_year(b, a);
		minutes += days_for_month_and_day(b, a);
	}
}

int minutes_in_day(datetime a)
{
	return a.hour * 60 + a.minute; 
}

int days_for_year(datetime a, datetime b)
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
	return days;
}

int days_for_month_and_day(datetime a, datetime b)
{
	int days = 0;
	int i;
	datetime start, end;

	/* use latest month as end point */
	if (a.month > b.month) {
		start = b;
		end = a;
	} else {
		start = a;
		end = b;
	}

	for(i = start.month; i < end.month; i++) {
		days += days_per_month[i - 1]
	}

	/* subtract beginning days of starting month from total */
	days -= start.day;

	/* subtract remaining days of end month from total */
	days -= (days_per_month[end.month - 1] - end.day);

	if (a.month < b.month) {
		return -1 * days;
	}

	return days;
}

int is_leap_year(int year)
{
	return 0;
}
