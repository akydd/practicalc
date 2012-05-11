/*
 * =============================================================================
 *
 *       Filename:  flight_info.h
 *
 *    Description:  Design a struct that contains the following airline
 *    		    reservation data: flight number, originating airport code
 *    		    (3 char code), dest airport code (3 char code), start time,
 *    		    arrival time.
 *
 *    		    I modified this to use datetime for start and arrival.
 *
 *        Version:  1.0
 *        Created:  11-12-25 03:56:16 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan Kydd (), akydd@ualberta.net
 *        Company:  
 *
 * =============================================================================
 */
#include "datetime.h"

struct flight_info {
	char flight[15];
	char origin[4];
	char destination[4];
	struct datetime *depart_dt;
	struct datetime *arrival_dt;
};

void print_flight_info(const struct flight_info *);

struct flight_info *create_flight_info(char *, char *, char *, int, int, int,
	       int, int, int, int, int, int, int);

void free_flight_info(struct flight_info *);
