/*
 * =============================================================================
 *
 *       Filename:  datetime.h
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

void print_datetime(const struct datetime *);
int diff_in_minutes(const struct datetime *, const struct datetime *);
int minutes_between_years(const struct datetime *, const struct datetime *);
int minutes_between_months(const struct datetime *, const struct datetime *);
int minutes_between_days(const struct datetime *, const struct datetime *);
int minutes_between_hours(const struct datetime *, const struct datetime *);
int minutes_between_minutes(const struct datetime *, const struct datetime *);
int minutes_between(const struct datetime *, const struct datetime *);
int minutes_in_year(const struct datetime *);
int is_leap_year(int);
struct datetime *create_datetime(const int, const int, const int, const int,
		const int);
void free_datetime(struct datetime *);
