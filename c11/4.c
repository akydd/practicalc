/*
 * =============================================================================
 *
 *       Filename:  4.c
 *
 *    Description:  A program to list all planes that leave from two airports
 *    		    specified by the user.  
 *
 *    		    To build: gcc -o4 4.c flight_info.c datetime.c -I -Wall
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

static struct flight_info *flights[MAX_FLIGHTS];

int is_quit(char *code)
{
	if (strlen(code) == 1) {
		if (code[0] == 'Q') {
			return 1;
		}
	}
	return 0;
}

void search_flights(char *dept_code)
{
	int i;
	for (i = 0; i < MAX_FLIGHTS; i++) {
		if (strcmp(flights[i]->origin, dept_code) == 0) {
			print_flight_info(flights[i]);
		}
	}
}

void get_airport_code(char *code)
{
	/* fgets returns NULL when error */
	if (fgets(code, 20, stdin) != NULL) {

		/* remove trailing newline if there is one */
		if (code[strlen(code) - 1] == '\n') {
			code[strlen(code) - 1] = '\0';
		} else {
			/* if no newline, input has exceeded buffer.
			 * Discard extra
			 */
			(void)scanf("%*[^\n]");
			(void)fgetc(stdin);
		}
	}
}

int main(void)
{
	char dept_code_1[20];
	char dept_code_2[20];

	/* test data */
	flights[0] = create_flight_info("WS 1423", "LAX", "YEG",
			2011, 12, 25, 14, 9,
		       	2011, 12, 25, 6, 25);	
	flights[1] = create_flight_info("WS 1487", "LAS", "YEG",
			2011, 12, 25, 19, 50,
			2011, 12, 25, 23, 55);
	flights[2] = create_flight_info("TACAT 4024", "YYC", "YEG", 
			2011, 12, 25, 22, 0,
			2011, 12, 25, 22, 54);
	flights[3] = create_flight_info("WS 145", "YYC", "YEG",
			2011, 12, 25, 22, 30,
			2011, 12, 25, 23, 19);

	while (1 == 1) {
		(void)printf("Enter first departure code, 'Q' to quit: ");
		get_airport_code(dept_code_1);
		if (is_quit(dept_code_1)) {
			(void)printf("Bye!\n");
			break;
		}

		(void)printf("Enter second departure code, 'Q' to quit: ");
		get_airport_code(dept_code_2);
		if (is_quit(dept_code_2)) {
			(void)printf("Bye!\n");
			break;
		}

		(void)printf("Seearching for %s...\n", dept_code_1);
		search_flights(dept_code_1);

		(void)printf("Seearching for %s...\n", dept_code_2);
		search_flights(dept_code_2);
	}
	return 0;
}
