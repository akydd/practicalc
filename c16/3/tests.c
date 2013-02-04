/*
 * ============================================================================
 *
 *       Filename:  tests.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  8/2/2012 2:17:35 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan Kydd akydd@ualberta.net
 *   Organization:  
 *
 * ============================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include "double_linked_list.h"

#define mu_assert(message, test) do { if (!(test)) return message; } while (0)
#define mu_run_test(test) do { char *message = test(); tests_run++; \
	if (message) return message; } while (0)

int tests_run = 0;

static char *test_insert_first()
{
	struct d_linked_list *my_list = NULL;

	insert(1, &my_list);

	mu_assert("List is null", my_list != NULL);
	mu_assert("New entry->prev is not null", my_list->prev == NULL);
	mu_assert("New entry->next is not null", my_list->next == NULL);
	mu_assert("New entry->item != 1", my_list->item == 1);

	free_list(&my_list);
	return 0;
}

static char *test_insert()
{
	struct d_linked_list *my_list = NULL;

	insert(1, &my_list);
	insert(5, &my_list);

	mu_assert("First entry is null", my_list != NULL);
	mu_assert("First entry->prev is not null", my_list->prev == NULL);
	mu_assert("First item != 5", my_list->item == 5);

	mu_assert("Second entry is null", my_list->next != NULL);
	mu_assert("Second entry->prev is null", my_list->next->prev != NULL);
	mu_assert("Second entry->prev != first entry", my_list->next->prev == my_list);
	mu_assert("Second item != 1", my_list->next->item == 1);
	mu_assert("Second entry->next is not null", my_list->next->next == NULL);

	free_list(&my_list);
	return 0;
}

static char *test_remove_head()
{
	struct d_linked_list *my_list = NULL;

	insert(1, &my_list);
	insert(3, &my_list);
	insert(2, &my_list);

	rem(1, &my_list);

	free_list(&my_list);
	return 0;
}

static char *test_remove_tail()
{
	struct d_linked_list *my_list = NULL;

	insert(1, &my_list);
	insert(3, &my_list);
	insert(2, &my_list);

	rem(2, &my_list);

	free_list(&my_list);
	return 0;
}

static char *test_remove_multiple()
{
	struct d_linked_list *my_list = NULL;

	insert(1, &my_list);
	insert(3, &my_list);
	insert(1, &my_list);
	insert(2, &my_list);

	rem(1, &my_list);

	free_list(&my_list);
	return 0;
}

static char *test_remove_middle()
{
	struct d_linked_list *my_list = NULL;

	insert(1, &my_list);
	insert(3, &my_list);
	insert(5, &my_list);

	rem(3, &my_list);

	free_list(&my_list);
	return 0;
}

static char *test_free_list()
{
	struct d_linked_list *my_list = NULL;

	insert(1, &my_list);
	insert(3, &my_list);
	insert(5, &my_list);

	free_list(&my_list);

	mu_assert("List not null", my_list == NULL);
	return 0;
}

static char *all_tests()
{
	mu_run_test(test_insert_first);
	mu_run_test(test_insert);
	mu_run_test(test_free_list);
	return 0;
}

int main()
{
	char *result = all_tests();
	if (result != 0) {
		(void)printf("%s\n", result);
	} else {
		(void)printf("All tests passed!\n");
	}
	(void) printf("Tests run: %d\n", tests_run);

	return result != 0;
}
