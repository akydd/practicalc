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

void insert_reference(int, struct list_node **);
void out_of_memory_so_exit();

void insert(char *word, int line, struct tree_node **node)
{
	if (*node == NULL) {
		*node = malloc(sizeof(struct tree_node));
		if (*node == NULL) {
			out_of_memory_so_exit();
		}
		
		(*node)->word = malloc(sizeof(strlen(word) + 1));
		if ((*node)->word == NULL) {
			out_of_memory_so_exit();
		}
		(void)strcpy((*node)->word, word);

		(*node)->references = NULL;
		insert_reference(line, &((*node)->references));

		(*node)->left = NULL;
		(*node)->right = NULL;
	} else {
		/* compare strings */
		int comp_int = strcmp(word, (*node)->word);

		if (comp_int < 0) {
			insert(word, line, &((*node)->left));
		} else if (comp_int > 0) {
			insert(word, line, &((*node)->right));
		} else {
			/* insert line & count into linked list */
			insert_reference(line, &((*node)->references));
		}
	}
}

void insert_reference(int line, struct list_node **node)
{
	if (*node == NULL) {
		*node = malloc(sizeof(struct list_node));
		if (*node == NULL) {
			out_of_memory_so_exit();
		}
		(*node)->line = line;
		(*node)->count = 1;
		(*node)->next = NULL;
	} else {
		if (line == (*node)->line) {
			(*node)->count++;
		} else {
			insert_reference(line, &((*node)->next));
		}
	}
}

void print_tree_node(struct tree_node *node)
{
	if (node == NULL) {
		return;
	}

	(void)print_tree_node(node->left);
	(void)printf("\"%s\" ", node->word);
	print_list_node(node->references);
	print_tree_node(node->right);
}

void print_list_node(struct list_node *node)
{
	if (node == NULL) {
		return;
	}

	(void)printf("appears in line %d, ", node->line);
	(void)printf("%d time(s).\n", node->count);
	print_list_node(node->next);
}

void out_of_memory_so_exit()
{
	(void)printf("Out of memory!");
	exit(EXIT_FAILURE);
}
