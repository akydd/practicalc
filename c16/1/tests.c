/*
 * ============================================================================
 *
 *       Filename:  tests.c
 *
 *    Description:  Test package for cross_ref.h  
 *
 *        Version:  1.0
 *        Created:  13-01-27 11:12:13 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan Kydd (), akydd@ualberta.net
 *   Organization:  
 *
 * ============================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cross_ref.h"

#define mu_assert(message, test) do { if (!(test)) return message; } while (0)
#define mu_run_test(test) do { char *message = test(); tests_run++; \
	if (message) return message; } while (0)

int tests_run = 0;

static char *test_free_list_node()
{
	struct list_node *entry = malloc(sizeof(struct list_node));
	entry->line = 2;
	entry->count = 0;
	entry->next = NULL;

	mu_assert("entry == NULL", entry != NULL);

	free_list_node(&entry);

	mu_assert("entry != NULL", entry == NULL);
	return 0;
}

static char *test_insert_reference_new_entry()
{
	struct list_node *entry = NULL;
	insert_reference(5, &entry);

	mu_assert("entry", entry != NULL);
	mu_assert("entry->line != 5", entry->line == 5);
	mu_assert("entry->count != 1", entry->count == 1);
	mu_assert("entry->next != NULL", entry->next == NULL);

	free_list_node(&entry);
	return 0;
}

static char *test_insert_reference_existing_entry_different_line()
{
	struct list_node *entry = malloc(sizeof(struct list_node));
	entry->line = 2;
	entry->count = 0;
	entry->next = NULL;

	insert_reference(3, &entry);

	mu_assert("Original count modified", entry->count == 0);
	mu_assert("Original line modified", entry->line == 2);
	mu_assert("New element not added", entry->next != NULL);
	mu_assert("New element->count != 1", entry->next->count == 1);
	mu_assert("New element->line != 3", entry->next->line == 3);
	mu_assert("New element->next != NULL", entry->next->next == NULL);

	free_list_node(&entry);
	return 0;
}

static char *test_insert_reference_existing_entry()
{
	struct list_node *entry = malloc(sizeof(struct list_node));
	entry->line = 2;
	entry->count = 0;
	entry->next = NULL;

	insert_reference(2, &entry);

	mu_assert("Error: count not incremented.", entry->count == 1);
	mu_assert("Error: line != 2", entry->line == 2);
	mu_assert("Error: new element added.", entry->next == NULL);

	free_list_node(&entry);
	return 0;
}

static char *test_insert_new_entry()
{
	struct tree_node *node = NULL;
	char *word = "New entry";
	insert(word, 1, &node);

	mu_assert("Error: new element not added", node != NULL);
	mu_assert("New entry has NULL word", node->word != NULL);
	mu_assert("New entry has wrong word", strcmp(word, node->word) == 0);
	mu_assert("No reference created", node->references != NULL);
	mu_assert("Reference has wrong line", node->references->line == 1);
	mu_assert("Reference has wrong count", node->references->count == 1);
	mu_assert("New entry has non-null left leaf", node->left == NULL);
	mu_assert("New entry has non-null right leaf", node->right == NULL);

	free_tree_node(&node);
	return 0;
}

static char *test_insert_duplicate_word_different_line()
{
	struct tree_node *node = NULL;
	char *word = "New entry";
	insert(word, 1, &node);
	insert(word, 2, &node);

	mu_assert("Existing node deleted", node != NULL);
	mu_assert("New entry has NULL word", node->word != NULL);
	mu_assert("New entry has wrong word", strcmp(word, node->word) == 0);
	mu_assert("Refs were deleted", node->references != NULL);
	mu_assert("Existing ref has wrong line", node->references->line == 1);
	mu_assert("Existing ref has wrong count", node->references->count == 1);
	mu_assert("New ref not created", node->references->next != NULL);
	mu_assert("New ref has wrong line", node->references->next->line == 2);
	mu_assert("New ref has wrong count", node->references->next->count == 1);
	mu_assert("New entry has non-null left leaf", node->left == NULL);
	mu_assert("New entry has non-null right leaf", node->right == NULL);

	free_tree_node(&node);
	return 0;
}


static char *test_insert_duplicate_word_same_line()
{
	struct tree_node *node = NULL;
	char *word = "New entry";
	insert(word, 1, &node);
	insert(word, 1, &node);

	mu_assert("Existing node deleted", node != NULL);
	mu_assert("New entry has NULL word", node->word != NULL);
	mu_assert("New entry has wrong word", strcmp(word, node->word) == 0);
	mu_assert("Existing reference deleted", node->references != NULL);
	mu_assert("Reference has wrong line", node->references->line == 1);
	mu_assert("Reference has wrong count", node->references->count == 2);
	mu_assert("New entry has non-null left leaf", node->left == NULL);
	mu_assert("New entry has non-null right leaf", node->right == NULL);

	free_tree_node(&node);
	return 0;
}

static char *test_insert_left_node()
{
	struct tree_node *node = NULL;
	char *head_word = "head";
	char *left_word = "ahead";
	insert(head_word, 1, &node);
	insert(left_word, 3, &node);

	mu_assert("Tree is null", node != NULL);
	mu_assert("Wrong head node word", strcmp(node->word, head_word) == 0);
	mu_assert("Wrong head node line", node->references->line == 1);
	mu_assert("Wrong head node count", node->references->count == 1);
	mu_assert("Right node not null", node->right == NULL);
	mu_assert("Left node null", node->left != NULL);
	mu_assert("Wrong left node word", strcmp(node->left->word, left_word) == 0);
	mu_assert("Wrong left node count", node->left->references->count == 1);
	mu_assert("Wrong left node line", node->left->references->line == 3);
	mu_assert("Extra left node ref", node->left->references->next == NULL);

	free_tree_node(&node);
	return 0;
}

static char *test_insert_right_node()
{
	struct tree_node *node = NULL;
	char *head_word = "head";
	char *right_word = "lead";
	insert(head_word, 1, &node);
	insert(right_word, 3, &node);

	mu_assert("Tree is null", node != NULL);
	mu_assert("Wrong head node word", strcmp(node->word, head_word) == 0);
	mu_assert("Wrong head node line", node->references->line == 1);
	mu_assert("Wrong head node count", node->references->count == 1);
	mu_assert("Left node not null", node->left == NULL);
	mu_assert("Right node null", node->right != NULL);
	mu_assert("Wrong right node word", strcmp(node->right->word, right_word) == 0);
	mu_assert("Wrong right node count", node->right->references->count == 1);
	mu_assert("Wrong right node line", node->right->references->line == 3);
	mu_assert("Extra right node ref", node->right->references->next == NULL);

	free_tree_node(&node);
	return 0;
}

static char *all_tests()
{
	mu_run_test(test_free_list_node);
	mu_run_test(test_insert_reference_new_entry);
	mu_run_test(test_insert_reference_existing_entry);
	mu_run_test(test_insert_reference_existing_entry_different_line);
	mu_run_test(test_insert_new_entry);
	mu_run_test(test_insert_duplicate_word_same_line);
	mu_run_test(test_insert_duplicate_word_different_line);
	mu_run_test(test_insert_left_node);
	mu_run_test(test_insert_right_node);
	return 0;
}

int main()
{
	char *result = all_tests();
	if (result != 0) {
		(void) printf("%s\n", result);
	} else {
		(void) printf("All tests passed!\n");
	}
	(void) printf("Tests run: %d\n", tests_run);

	return result != 0;
}
