/*
 * =============================================================================
 *
 *       Filename:  2.h
 *
 *    Description:  Define a struct for datetime.
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
struct datetime {
	int year;
	int month;
	int day;
	int hour;
	int minute;
};

int diff_in_minutes(struct datetime, struct datetime);
int minutes_between_years(struct datetime, struct datetime);
int minutes_between_months(struct datetime, struct datetime);
int minutes_between_days(struct datetime, struct datetime);
int minutes_between_hours(struct datetime, struct datetime);
int minutes_between_minutes(struct datetime, struct datetime);
int minutes_between(struct datetime, struct datetime);
int minutes_in_year(struct datetime);
int is_leap_year(int);
