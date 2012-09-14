/*
 * ============================================================================
 *
 *       Filename:  symbol_table.c
 *
 *    Description:  Symbol table functions
 *
 *        Version:  1.0
 *        Created:  12-09-12 08:19:52 PM
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
#include <string.h>
#include <stdio.h>

struct table *symbol_table = NULL;

void enter(char *name)
{
	/* malloc entry and cpy name into it */
	struct table *new_symbol = malloc(sizeof(struct table));
	new_symbol->name = malloc(sizeof(int) * (strlen(name) + 1));
	(void)strcpy(new_symbol->name, name);

	/* add entry to front of list */
	new_symbol->next = symbol_table;
	new_symbol->prev = NULL;
	if (symbol_table != NULL) {
		symbol_table->prev = new_symbol;
	}
	symbol_table = new_symbol;
}

int lookup(char *name)
{
	/* sequential search, starting at front of list */
	struct table *search = symbol_table;

	while((search != NULL) && (strcmp(name, search->name) != 0)) {
		search = search->next;
	}

	return (search != NULL);
}

void delete(char *name)
{
	/* again, search from front of list */
	struct table *search = symbol_table;

	while((search != NULL) && (strcmp(name, search->name) != 0)) {
		search = search->next;
	}

	/* if found, delete the element */
	if (search != NULL) {
		/* first unlink */
		if(search->prev != NULL) {
			search->prev->next = search->next;
		}
		if(search->next != NULL) {
			search->next->prev = search->prev;
		}
		/* then free */
		free(search->name);
		free(search);
	}
}

void print(void)
{
	struct table *search = symbol_table;

	while(search != NULL) {
		(void)printf("Name: %s\n", search->name);

		if(search->prev != NULL) {
			(void)printf("Prev: %s\n", search->prev->name);
		}
		if(search->next != NULL) {
			(void)printf("Next: %s\n", search->next->name);
		}

		(void)printf("\n");
		search = search->next;
	}
}

void delete_table(void)
{
	struct table *search = symbol_table;
	struct table *next;

	while(search != NULL) {
		next = search->next;
		free(search->name);
		free(search);
		search = next;
	}
}
