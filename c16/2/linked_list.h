/*
 * =============================================================================
 *
 *       Filename:  linked_list.h
 *
 *    Description:  unordered linked list (for integers) definitions.
 *		    Allows for duplicate list items. 
 *
 *        Version:  1.0
 *        Created:  8/2/2012 1:20:05 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan Kydd (), akydd@ualberta.net
 *   Organization:  
 *
 * =============================================================================
 */

struct linked_list {
	int item;
	struct linked_list *next;
};

void insert(int, struct linked_list **);

/**
 * Removes _first occurence_ of int from list.
 */
void rem(int, struct linked_list **);

void print(struct linked_list *);

void free_list(struct linked_list **);
