/*
 * =====================================================================================
 *
 *       Filename:  2.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  8/2/2012 2:17:35 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan Kydd akydd@ualberta.net
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include "linked_list.h"

int main()
{
	struct linked_list *my_list = NULL;

	insert(1, &my_list);
	insert(2, &my_list);
	insert(3, &my_list);

	print(my_list);
	exit(EXIT_SUCCESS);
}
