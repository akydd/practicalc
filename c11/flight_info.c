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

void print_flight_info(struct flight_info the_flight)
{
	(void)printf("Flight into starts =>\n");
	(void)printf("Flight %s\n", the_flight.flight);
	(void)printf("  Leaving from %s\n", the_flight.origin);
	(void)printf("    at ");
	print_datetime(the_flight.depart_dt);
	(void)printf("\n");
	(void)printf("  Arriving at %s\n", the_flight.destination);
	(void)printf("    at ");
	print_datetime(the_flight.arrival_dt);
	(void)printf("\n\n");
}
