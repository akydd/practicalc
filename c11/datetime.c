/*
 * =============================================================================
 *
 *       Filename:  datetime.c
 *
 *    Description:  datetime implementation
 *
 *        Version:  1.0
 *        Created:  11-12-25 04:04:00 PM
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

/* array stored #days/month for non leap-years */
int days_per_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/*
 * Function to print the datetime, nicely formatted.
 */
void print_datetime(struct datetime a)
{
	(void)printf("%d-%d-%d, %d:%d",
			a.year, a.month, a.day, a.hour, a.minute);
}

/**
 * function returns the difference, in minutes, between two datetime structs.
 */
int diff_in_minutes(struct datetime a, struct datetime b)
{
	int minutes = 0;

	/* formula for total minutes is
	 * sum of total minutes in all years from start year to end year-1
	 *  + minutes in end year
	 *  - skipped minutes from beginning of start year
	 */

	/* subtract earlier year from later */
	if (a.year > b.year) {
		minutes += minutes_between_years(a, b);
		minutes += minutes_in_year(a);
		minutes -= minutes_in_year(b);
	} else if (b.year > a.year) {
		minutes += minutes_between_years(b, a);
		minutes += minutes_in_year(b);
		minutes -= minutes_in_year(a);
	} else {
		/* years are equal, so get the diff of months */
		minutes += minutes_between_months(a, b);
	}

	return minutes;
}

/**
 * Assuming years are equal, function returns the difference, in minutes,
 * between to datetime structs.
 */
int minutes_between_months(struct datetime a, struct datetime b)
{
	/* subtract minutes up to the recent month
	 * from minutes up to theearlier month */
	if (a.month > b.month) {
		return minutes_between(a, b);
	} else if (b.month > a.month) {
		return minutes_between(b, a);
	}

	/* months are equal, so get the diff of days */
	return minutes_between_days(a, b);
}

/**
 * Assuming months and years are equal, function returns the difference,
 * in minutes, between two datetime structs
 */
int minutes_between_days(struct datetime a, struct datetime b)
{
	/* subtract minutes up to most recent day
	 * from minutes up to the earlier day */
	if (a.day > b.day) {
		return minutes_between(a, b);
	} else if (b.day > a.day) {
		return minutes_between(b, a);
	} 

	/* days are equal, so get the diff for hours */
	return minutes_between_hours(a, b);
}

/**
 * Assuming days, months, and years are equal, function returns the difference,
 * in minutes, between two datetime structs.
 */
int minutes_between_hours(struct datetime a, struct datetime b)
{
	/* subtract minutes up to the earlier hour
	 * from minutes up to the later hour */
	if (a.hour > b.hour) {
		return minutes_between(a, b);
	} else if (b.hour > a.hour) {
		return minutes_between(b, a);
	}

	/* hours are equal, so get diff of minutes */
	return minutes_between_minutes(a, b);
}

/**
 * Assuming hours, days, months, and years are equal, function returns the
 * difference, in minutes, between two datetime structs.
 */
int minutes_between_minutes(struct datetime a, struct datetime b)
{
	/* subtract earlier minutes from later minutes */
	if (a.minute > b.minute) {
		return minutes_between(a, b);
	}

	return minutes_between(b, a);
}

int minutes_between(struct datetime a, struct datetime b)
{
	return minutes_in_year(a) - minutes_in_year(b);
}

/**
 * Returns the number of minutes passed from the start of year b to the start
 * of year a.
 */
int minutes_between_years(struct datetime a, struct datetime b)
{
	int days = 0;
	int i;

	for(i = b.year; i < a.year; i++) {
		if (is_leap_year(i) == 1) {
			days += 366;
		} else {
			days += 365;
		}
	}
	return days * 24 * 60;
}

/**
 * Function returns the number of minutes elapsed in one year, up to the given
 * datetime of that same year.
 */
int minutes_in_year(struct datetime a)
{
	int days = 0;
	int i;

	for(i = 1; i < a.month; i++) {
		/* add extra day if it's february and a leap year */
		if ((is_leap_year(a.year) == 1) && (i == 2)) {
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

/**
 * Returns 1 the int is a leap year. 0 otherwise.
 * Taken from exercise 5.5.
 */
int is_leap_year(int year)
{
	int leap_year_bool = 0;

	if ((year % 4) == 0)
	{
		if ((year % 100) == 0)
		{
			if ((year % 400) != 0)
			{
				leap_year_bool = 0;
			}
			else
			{
				leap_year_bool = 1;
			}
		}
		else
		{
			leap_year_bool = 1;
		}
	}
	else
	{
		leap_year_bool = 0;
	}
	return leap_year_bool;
}

