/*
 * =============================================================================
 *
 *       Filename:  1.h
 *
 *    Description:  Header for cross reference data structure.
 *                  Description was vague, so this data structure is used
 *                  for reading in words from a text file, storing the line
 *                  each word appears on, and the number of times each word
 *                  appears in each line.
 *
 *        Version:  1.0
 *        Created:  12-07-30 10:10:53 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan Kydd (), akydd@ualberta.net
 *        Company:  
 *
 * =============================================================================
 */

struct list_node {
	int line;
	int count;
	struct list_node *next;
};

struct tree_node {
	char *word;
	struct list_node *references;
	struct tree_node *left;
	struct tree_node *right;
};

void insert(char *, int, struct tree_node **);

void print_tree_node(struct tree_node *);

void print_list_node(struct list_node *);

void free_tree_node(struct tree_node **);
