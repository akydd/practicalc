/*
 * =============================================================================
 *
 *       Filename:  double_linked_list.h
 *
 *    Description:  Defs for unordered, double linked list
 *
 *        Version:  1.0
 *        Created:  12-08-05 08:35:22 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan Kydd (), akydd@ualberta.net
 *        Company:  
 *
 * =============================================================================
 */

struct d_linked_list {
	int item;
	struct d_linked_list *prev;
	struct d_llinked_list *next;
}

void insert(int, struct d_linked_list **);

void rem(int, struct d_linked_list **);

void print(struct d_linked_list *);

void free_list(struct d_linked_list **);
