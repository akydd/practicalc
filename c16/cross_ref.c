/*
 * =============================================================================
 *
 *       Filename:  cross_ref.c
 *
 *    Description:  Implementation of cross_ref.h
 *
 *        Version:  1.0
 *        Created:  12-07-30 10:25:02 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan Kydd (), akydd@ualberta.net
 *        Company:  
 *
 * =============================================================================
 */
#include "cross_ref.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void insert(char *word, int line, struct tree_node **node)
{
	if (*node == NULL) {
		*node = malloc(sizeof(tree_node));
		//*node->word = word;
		*node->left = NULL;
		*node->right = NULL;
	} else {
		/* compare strings */
		int comp_int = strcmp(word, *node->word);

		if (comp_int < 0) {
			insert(word, line, &(*node->left));
		} else if (comp_int > 0) {
			insert(word, line, &(*node->right));
		} else {
			/* insert line & count into linked list */
			insert(int line, &(*node->references));
		}
	}
}

void insert(int line, struct list_node **node)
{
	if (*node == NULL) {
		*node = malloc(sizeof(list_node));
		*node->line = line;
		*node->count = 1;
		*node->next = NULL;
	} else {
		if (line == *node->line) {
			*node->count++;
		} else {
			insert(line, &(*node->next));
		}
	}
}

void print_tree_node(struct tree_node *node)
{
	if (node == NULL) {
		return;
	}

	(void)print_tree_node(node->left);
	(void)printf("Word: %s\n");
	print_list_node(node->references);
	print_tree_node(node->right);
}

void print_list_node(struct list_node *node)
{
	if (node == NULL) {
		return;
	}

	(void)printf("Line: %d\n", node->line);
	(void)printf("Count: %d\n", node->count);
	print_list_node(node->next);
}
