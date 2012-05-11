/*
 * =============================================================================
 *
 *       Filename:  flight_info.c
 *
 *    Description:  Implementation for flight_info.h
 *
 *        Version:  1.0
 *        Created:  11-12-26 09:37:15 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan Kydd (), akydd@ualberta.net
 *        Company:  
 *
 * =============================================================================
 */
#include <stdio.h>
#include "flight_info.h"
#include "datetime.h"

void free_flight_info(struct flight_info *the_flight)
{
	free(the_flight->depart_dt);
	free(the_flight->arrival_dt);
	free(the_flight);
}

struct flight_info *create_flight_info(char *flight, char *origin, char *destination,
		int d_yaer, int d_month, int d_day, int d_hour, int d_min,
		int a_year, int a_month, int a_day, int a_hour, int a_min)
{
	struct flight_info *the_flight = malloc(sizeof(struct flight_info));

	struct datetime *depart_dt = create_datetime(d_year, d_month, d_day, 
			d_hour, d_min);
	struct datetime *arrival_dt = create_datetime(a_year, a_month, a_day,
			a_hour, a_min);
	flight_info->depart_dt = depart_dt;
	flight_info->arrival_dt = arrival_dt;

	flight_info->flight = flight;
	flight_info->origin = origin;
	flight_info->destination = destination;

	return flight_info;
}

void print_flight_info(struct flight_info *the_flight)
{
	(void)printf("Flight into starts =>\n");
	(void)printf("Flight %s\n", the_flight->flight);
	(void)printf("  Leaving from %s\n", the_flight->origin);
	(void)printf("    at ");
	print_datetime(the_flight->depart_dt);
	(void)printf("\n");
	(void)printf("  Arriving at %s\n", the_flight->destination);
	(void)printf("    at ");
	print_datetime(the_flight->arrival_dt);
	(void)printf("\n\n");
}
