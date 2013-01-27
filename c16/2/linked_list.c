/*
 * =============================================================================
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
 * =============================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

void out_of_memory_error();

void insert(int item, struct linked_list **head)
{
	/* init new list element */
	struct linked_list *new_int = malloc(sizeof(struct linked_list));
	if (new_int == NULL) {
		out_of_memory_error();
	}
	new_int->item = item;
	
	/* link */
	new_int->next = *head;
	*head = new_int;
}

void rem(int item, struct linked_list **head)
{
	struct linked_list **list_ptr = head;
	while(*list_ptr != NULL) {
		if((*list_ptr)->item == item) {
			struct linked_list *delete = *list_ptr;
			*list_ptr = delete->next;
			free(delete);
		} else {
			list_ptr = &(*list_ptr)->next;
		}
	}
}

void free_list(struct linked_list **head)
{
	while(*head != NULL) {
		struct linked_list *entry = *head;
		*head = entry->next;
		free(entry);
	}
}

void out_of_memory_error()
{
	(void)printf("Out of memory!");
	exit(EXIT_FAILURE);
}
