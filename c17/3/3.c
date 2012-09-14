/*
 * ============================================================================
 *
 *       Filename:  3.c
 *
 *    Description:  Test for the symbol_table module
 *
 *        Version:  1.0
 *        Created:  12-09-12 09:47:14 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan Kydd (), akydd@ualberta.net
 *   Organization:  
 *
 * ============================================================================
 */
#include <stdlib.h>
#include "symbol_table.h"

int main(void)
{
	enter("Added first");
	enter("Added second");
	enter("Added but will be deleted");
	enter("The last shall be first");

	print();

	delete("Not there");
	print();

	delete("Added but will be deleted");
	print();

	delete_table();

	exit(EXIT_SUCCESS);
}
