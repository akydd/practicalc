/*
 * =============================================================================
 *
 *       Filename:  bstree.h
 *
 *    Description:  Binary search tree function prototypes.  No duplicate keys.
 *
 *        Version:  1.0
 *        Created:  12-08-07 07:25:38 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan Kydd (), akydd@ualberta.net
 *        Company:  
 *
 * =============================================================================
 */

struct bstree {
	int item;
	struct bstree *left;
	struct bstree *right;
};

void insert(int, struct bstree **);

/**
 * Remove the only occurance from the tree
 */
void rem(int, struct bstree **);

void print(struct bstree *, int);

void free_bstree(struct bstree **);
