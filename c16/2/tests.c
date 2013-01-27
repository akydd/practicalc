/*
 * ============================================================================
 *
 *       Filename:  tests.c
 *
 *    Description:  
 *
 *        Version:  1.1
 *        Created:  2013-01-26 12:35 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan Kydd akydd@ualberta.net
 *   Organization:  
 *
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

#define mu_assert(message, test) do { if (!(test)) return message; } while (0)
#define mu_run_test(test) do { char *message = test(); tests_run++; \
	if (message) return message; } while (0)

int tests_run = 0;

static char *test_insert() {
	struct linked_list *my_list = NULL;
	insert(1, &my_list);
	insert(2, &my_list);
	insert(3, &my_list);

	mu_assert("error, element != 3", my_list->item == 3);
	mu_assert("error, element != 2", my_list->next->item == 2);
	mu_assert("error, element != 1", my_list->next->next->item == 1);

	free_list(&my_list);
	return 0;
}

static char *test_remove_head() {
	struct linked_list *my_list = NULL;
	insert(1, &my_list);
	insert(2, &my_list);

	rem(2, &my_list);

	mu_assert("error, element != 1", my_list->item == 1);
	mu_assert("error, element != NULL", my_list->next == NULL);

	free_list(&my_list);
	return 0;
}

static char *test_remove_tail() {
	struct linked_list *my_list = NULL;
	insert(1, &my_list);
	insert(2, &my_list);

	rem(1, &my_list);

	mu_assert("error, element != 2", my_list->item == 2);
	mu_assert("error, element != NULL", my_list->next == NULL);

	free_list(&my_list);
	return 0;
}

static char *test_remove() {
	struct linked_list *my_list = NULL;
	insert(1, &my_list);
	insert(2, &my_list);
	insert(1, &my_list);
	insert(1, &my_list);
	insert(2, &my_list);

	rem(1, &my_list);

	mu_assert("error, element != 2", my_list->item == 2);
	mu_assert("error, element != 2", my_list->next->item == 2);

	rem(2, &my_list);

	mu_assert("error, list not empty", my_list == NULL);

	free_list(&my_list);
	return 0;
}

static char *all_tests() {
	mu_run_test(test_insert);
	mu_run_test(test_remove_head);
	mu_run_test(test_remove_tail);
	mu_run_test(test_remove);
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
