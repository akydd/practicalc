/*
 * ============================================================================
 *
 *       Filename:  symbol_table.h
 *
 *    Description:  Symbol table functions
 *
 *        Version:  1.0
 *        Created:  12-09-12 08:10:35 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan Kydd (), akydd@ualberta.net
 *   Organization:  
 *
 * ============================================================================
 */
#include <stdlib.h>

/* symbol table is implemented as an intrusive double-linked list */
struct table {
	char *name;
	struct table *next;
	struct table *prev;
};
struct table *symbol_table = NULL;

/* 
 * Enter a name into the symbol table
 */
void enter(char *);

/*
 * returns 1 if name is in the table, 0 otherwise
 */
int lookup(char *);

/* 
 * Remove a name from the symbol table
 */
void delete(char *);

/*
 * print the symbol table */
void print(void);

/* 
 * delete the entire table
 */
void delete_table(void);
