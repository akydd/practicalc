/*
 * =============================================================================
 *
 *       Filename:  4.c
 *
 *    Description:  A program to list all planes that leave from two airports
 *    		    specified by the user.  NOT FINISHED!
 *
 *        Version:  1.0
 *        Created:  11-12-25 07:56:23 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan Kydd (), akydd@ualberta.net
 *        Company:  
 *
 * =============================================================================
 */
#include <stdio.h>
#include <string.h>
#include "flight_info.h"
#define MAX_FLIGHTS 4

static struct flight_info flights[MAX_FLIGHTS];

int main(void)
{
	char dept_code_1[3];
	char dept_code_2[3];
	char buffer[10];
	int result = 0;

	/* test data */
	struct flight_info flight_0 = {
		"WS 1423",
		"LAX",
		"YEG",
		{2011, 12, 25, 14, 9},
		{2011, 12, 25, 6, 25}
	};
	flights[0] = flight_0;

	struct flight_info flight_1 = {
		"WS 1487",
		"LAS",
		"YEG",
		{2011, 12, 25, 19, 50},
		{2011, 12, 25, 23, 55}
	};
	flights[1] = flight_1;

	struct flight_info flight_2 = {
		"TACAT 4024",
		"YYC",
		"YEG",
		{2011, 12, 25, 22, 0},
		{2011, 12, 25, 22, 54}
	};
	flights[2] = flight_2;

	struct flight_info flight_3 = {
		"WS 145",
		"YYC",
		"YEG",
		{2011, 12, 25, 22, 30},
		{2011, 12, 25, 23, 19}
	};
	flights[3] = flight_3;

	while (1 == 1) {
		buffer[0] = '\0';
		(void)printf("Enter first 3 letter departure code: ");
		(void)fgets(buffer, sizeof(buffer), stdin);
		result = sscanf(buffer, "%4s", dept_code_1);
		buffer[0] = '\0';
		(void)printf("Enter second 3 letter departure code: ");
		(void)fgets(buffer, sizeof(buffer), stdin);
		result = sscanf(buffer, "%4s", dept_code_2);

		(void)printf("%s\n", dept_code_1);
		(void)printf("%s\n", dept_code_2);
	}
	return 0;
}
