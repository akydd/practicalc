/*
 * ============================================================================
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
 * ============================================================================
 */
#include "cross_ref.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void insert_reference(int, struct list_node **);
void free_list_node(struct list_node **);
void out_of_memory_so_exit();

void insert(char *word, int line, struct tree_node **node)
{
	if (*node == NULL) {
		*node = malloc(sizeof(struct tree_node));
		if (*node == NULL) {
			out_of_memory_so_exit();
		}

		(*node)->word = malloc((strlen(word) + 1) * sizeof(char));
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
	struct list_node **current = node;
	while(*current != NULL) {
		if(line == (*current)->line) {
			(*current)->count++;
			return;
		} else {
			current = &((*current)->next);
		}
	}

	/* no existing reference exists, create a new one. */
	*current = malloc(sizeof(struct list_node));
	if (*current == NULL) {
		out_of_memory_so_exit();
	}
	(*current)->line = line;
	(*current)->count = 1;
	(*current)->next = NULL;
}

void print_tree_node(struct tree_node *node)
{
	if (node == NULL) {
		return;
	}

	print_tree_node(node->left);

	(void)printf("\"%s\"\n", node->word);
	print_list_node(node->references);

	print_tree_node(node->right);
}

void free_tree_node(struct tree_node **node)
{
	if (*node == NULL) {
		return;
	}

	/* first free each branch */
	free_tree_node(&((*node)->left));
	free_tree_node(&((*node)->right));
	/* then free up the internals */
	free_list_node(&((*node)->references));
	(void)free((*node)->word);
	/* then free up the node */
	(void)free(*node);
}

void free_list_node(struct list_node **node)
{
	while(*node != NULL) {
		struct list_node *delete = *node;
		*node = delete->next;
		free(delete);
	}
}

void print_list_node(struct list_node *node)
{
	while (node != NULL) {
		(void)printf("\tappears in line %d, ", node->line);
		(void)printf("%d time(s).\n", node->count);
		node = node->next;
	}
}

void out_of_memory_so_exit()
{
	(void)printf("Out of memory!");
	exit(EXIT_FAILURE);
}
