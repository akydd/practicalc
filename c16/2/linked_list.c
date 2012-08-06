/*
 * =====================================================================================
 *
 *       Filename:  linked_list.c
 *
 *    Description:  Implementation of the unordered linked list of integers
 *
 *        Version:  1.0
 *        Created:  8/2/2012 1:32:08 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan Kydd, akydd@ualberta.net
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

void out_of_memory_error();

void insert(int item, struct linked_list **list)
{
	if (*list == NULL) {
		*list = malloc(sizeof(struct linked_list));
		if (*list == NULL) {
			out_of_memory_error();
		}

		(*list)->item = item;
		(*list)->next = NULL;
	} else {
		/* 
		 * could have iterated past non-null
		 * nodes here instead of using recursion
		 */
		insert(item, &((*list)->next));
	}
}

void rem(int item, struct linked_list **list)
{
	if (*list == NULL) {
		return;
		/* do nothing */
	}

	struct linked_list *search_ptr = *list;
	/* check first item in list */
	if (search_ptr->item == item) {
		*list = search_ptr->next;
		free(search_ptr);
	} else {
		while (search_ptr->next != NULL) {
			if(search_ptr->next->item != item) {
				search_ptr = search_ptr->next;
			} else {
				struct linked_list *del_ptr = search_ptr->next;
				search_ptr->next = del_ptr->next;
				free(del_ptr);
				break;
			}
		}
	}
}

void print(struct linked_list *list)
{
	/* iterate and print */
	int i = 0;
	struct linked_list *list_ptr = list;
	while(list_ptr != NULL) {
		(void)printf("Item %d: %d\n", i, list_ptr->item);
		i++;
		list_ptr = list_ptr->next;
	}
	(void)printf("\n");
}

void free_list(struct linked_list **list)
{
	if (*list == NULL) {
		return;
	}
	free_list(&((*list)->next));
	free(*list);
}

void out_of_memory_error()
{
	(void)printf("Out of memory!");
	exit(EXIT_FAILURE);
}
