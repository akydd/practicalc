/*
 * =============================================================================
 *
 *       Filename:  3.c
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
 * =============================================================================
 */
#include <stdlib.h>
#include "double_linked_list.h"

int main()
{
	struct d_linked_list *my_list = NULL;

	insert(1, &my_list);
	insert(3, &my_list);
	insert(5, &my_list);
	insert(2, &my_list);
	insert(4, &my_list);
	insert(5, &my_list);

	print(my_list);
	rem(1, &my_list);
	print(my_list);
	rem(2, &my_list);
	print(my_list);
	rem(5, &my_list);
	print(my_list);
	rem(10, &my_list);
	print(my_list);
	rem(5, &my_list);
	print(my_list);

	free_list(&my_list);
	exit(EXIT_SUCCESS);
}
