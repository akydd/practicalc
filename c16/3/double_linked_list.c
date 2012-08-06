/*
 * =============================================================================
 *
 *       Filename:  double_linked_list.c
 *
 *    Description:  Implementation of unordered double linked list
 *
 *        Version:  1.0
 *        Created:  12-08-05 08:38:34 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan Kydd (), akydd@ualberta.net
 *        Company:  
 *
 * =============================================================================
 */
#include "d_linked_list.h"
#include <stdlib.h>
#include <stdio.h>

void insert(int item, struct d_linked_list **list)
{
	if (*list == NULL) {
		*list = malloc(sizeof(struct d_linked_list));
		if (*list == NULL) {
			out_of_memory_error();
		}
		(*list)->next = NULL;
		(*list)->prev = NULL;
		(*list)->item = item;
	} else {
		/* find the end of the list and insert there */
		struct d_liked_list *item = *list;
	}
}
