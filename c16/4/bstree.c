/*
 * =============================================================================
 *
 *       Filename:  bstree.c
 *
 *    Description:  bstree impl
 *
 *        Version:  1.0
 *        Created:  12-08-07 07:35:04 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan Kydd (), akydd@ualberta.net
 *        Company:  
 *
 * =============================================================================
 */
#include "bstree.h"
#include <stdio.h>
#include <stdlib.h>

void insert(int item, struct bstree **tree)
{
	if(*tree == NULL) {
		*tree = malloc(sizeof(struct bstree));
		(*tree)->item = item;
		(*tree)->left = NULL;
		(*tree)->right = NULL;
	} else {
		if (item < (*tree)->item) {
			insert(item, &((*tree)->left));
		} else if (item > (*tree)->item) {
			insert(item, &((*tree)->right));
		}
	}
}

void rem(int item, struct bstree **tree)
{

}

void print(struct bstree *tree, int lvl)
{
	int i;
	if (tree == NULL) {
		return;
	} else {
		print(tree->right, lvl + 1);
		for(i = 0; i < lvl; i++) {
			(void)printf(" ");
		}
		(void)printf("%d\n", tree->item);
		print(tree->left, lvl + 1);
	}
}

void free_bstree(struct bstree **tree)
{
	if (*tree == NULL) {
		return;
	} else {
		free_bstree(&((*tree)->left));
		free_bstree(&((*tree)->right));
		free(*tree);
	}
}
