/*
 * =============================================================================
 *
 *       Filename:  boolean.h
 *
 *    Description:  Defines BOOLEAN type and macros for exercises 2, 3, 4, 5
 *
 *        Version:  1.0
 *        Created:  11-11-21 07:57:50 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan Kydd (), akydd@ualberta.net
 *        Company:  
 *
 * =============================================================================
 */

#define BOOLEAN int
#define TRUE 1
#define FALSE 0

#define is_div_10(x) (((x)%10 == 0) ? TRUE : FALSE)

/* exercise doesn't specify, but the args to the next 5 macros are chars */
#define is_digit(x) (( ((x) <= '9') && ((x) >= '0') ) ? TRUE : FALSE)
#define is_AF(x) (( ((x) >= 'A') && ((x) <= 'F') ) ? TRUE : FALSE)
#define is_af(x) (( ((x) >= 'a') && ((x) <= 'f') ) ? TRUE : FALSE)
#define is_AFaf(x) ( ((is_AF(x) == TRUE) || (is_af(x) == TRUE)) ? TRUE : FALSE)
#define is_hex(x) ( ((is_digit(x) == TRUE) || (is_AFaf(x) == TRUE)) ? TRUE : FALSE)


/* swap 2 ints.  Doesn't use a tmp var declared outside of the macro! :) */
#define swap(x, y) (x) += (y);(y) = (x) - (y);(x) -= (y)
