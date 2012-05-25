/*
 * =============================================================================
 *
 *       Filename:  float_10.h
 *
 *    Description:  float_10 and operations definitions
 *
 *        Version:  1.0
 *        Created:  12-05-24 10:45:48 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan Kydd (), akydd@ualberta.net
 *        Company:  
 *
 * =============================================================================
 */

/* internal representation of base 10 float */
struct float_10 {
	int digit;
	int fraction;
	int exponent;
};

/* Read in a string, convert and store as float_10 */
void read_float(char [9], struct float_10 *);

/* Store string rep of struct float_10 in char * */
char *write_float(struct float_10 *, char *);


