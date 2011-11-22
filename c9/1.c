/*
 * =============================================================================
 *
 *       Filename:  1.c
 *
 *    Description:  Test definitions for BOOLEAN, TRUE, FALSE
 *
 *        Version:  1.0
 *        Created:  11-11-21 07:49:43 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan Kydd (), akydd@ualberta.net
 *        Company:  
 *
 * =============================================================================
 */
#include <stdio.h>
#include "boolean.h"

int main(void)
{
	/* use the defs for BOOLEAN */
	BOOLEAN true_value;
	BOOLEAN false_value;

	true_value = TRUE;
	false_value = FALSE;

	if (true_value == TRUE) {
		(void)printf("true_value is true.\n");
	}

	if (false_value == FALSE) {
		(void)printf("false_value is false.\n");
	}

	return 0;
}
