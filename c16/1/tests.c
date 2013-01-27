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

static char *all_tests()
{
	mu_run_test(test_free_list_node);
	mu_run_test(test_insert_reference_new_entry);
	mu_run_test(test_insert_reference_existing_entry);
	mu_run_test(test_insert_reference_existing_entry_different_line);
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
