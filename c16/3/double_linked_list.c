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
#include "double_linked_list.h"
#include <stdlib.h>
#include <stdio.h>

void out_of_memory_error();

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
		struct d_linked_list *list_ptr = *list;
		while (list_ptr->next != NULL) {
			list_ptr = list_ptr->next;
		}
		list_ptr->next = malloc(sizeof(struct d_linked_list));
		if (list_ptr->next == NULL) {
			out_of_memory_error();
		}
		list_ptr->next->prev = list_ptr;
		list_ptr->next->next = NULL;
		list_ptr->next->item = item;
	}
}

void rem(int item, struct d_linked_list **list)
{
	/* special case if head of list gets deleted */
	if ((*list)->item == item) {
		struct d_linked_list *tmp_ptr = *list;
		*list = (*list)->next;
		tmp_ptr->prev == NULL;
		free(tmp_ptr);
	}

	/* tranverse list looking for first match */
	struct d_linked_list *search_ptr = *list;
	while (search_ptr != NULL) {
		if (search_ptr->item == item) {
			if (search_ptr->next != NULL) {
				search_ptr->next->prev = search_ptr->prev;
			}
			if (search_ptr->prev != NULL) {
				search_ptr->prev->next = search_ptr->next;
			}
			free(search_ptr);
			break;
		} else {
			search_ptr = search_ptr->next;
		}
	}
}

void print(struct d_linked_list *list)
{
	int i = 0;
	struct d_linked_list *search_ptr = list;
	while(search_ptr != NULL) {
		(void)printf("Item %d: ", i);
		(void)(printf("%d\n", search_ptr->item));
		search_ptr = search_ptr->next;
		i++;
	}
	(void)printf("\n");
}

void free_list(struct d_linked_list **list)
{
	struct d_linked_list *search_ptr = *list;
	while(search_ptr != NULL) {
		struct d_linked_list *tmp_ptr = search_ptr->next;
		free(search_ptr);
		search_ptr = tmp_ptr;
	}
}

void out_of_memory_error()
{
	(void)printf("Out of memory!\n");
	exit(EXIT_FAILURE);
}
