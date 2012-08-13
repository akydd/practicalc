/*
 * =============================================================================
 *
 *       Filename:  4.c
 *
 *    Description:  Test out the bstree
 *
 *        Version:  1.0
 *        Created:  12-08-07 08:21:47 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan Kydd (), akydd@ualberta.net
 *        Company:  
 *
 * =============================================================================
 */
#include "bstree.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
	struct bstree *mytree = NULL;

	insert(4, &mytree);
	print(mytree, 0);
	(void)printf("\n\n");

	insert(2, &mytree);
	print(mytree, 0);
	(void)printf("\n\n");

	insert(6, &mytree);
	print(mytree, 0);
	(void)printf("\n\n");

	insert(1, &mytree);
	print(mytree, 0);
	(void)printf("\n\n");

	insert(3, &mytree);
	print(mytree, 0);
	(void)printf("\n\n");

	insert(5, &mytree);
	print(mytree, 0);
	(void)printf("\n\n");

	insert(7, &mytree);
	print(mytree, 0);
	(void)printf("\n\n");

	rem(3, &mytree);
	print(mytree, 0);
	(void)printf("\n\n");

	rem(6, &mytree);
	print(mytree, 0);
	(void)printf("\n\n");

	rem(4, &mytree);
	print(mytree, 0);
	(void)printf("\n\n");

	rem(9, &mytree);
	print(mytree, 0);
	(void)printf("\n\n");

	free_bstree(&mytree);
	exit(EXIT_SUCCESS);
}
