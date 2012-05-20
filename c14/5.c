/*
 * =============================================================================
 *
 *       Filename:  5.c
 *
 *    Description:  My own version of memcpy
 *
 *        Version:  1.0
 *        Created:  12-05-20 09:27:29 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan Kydd (), akydd@ualberta.net
 *        Company:  
 *
 * =============================================================================
 */
#include <stdio.h>

void *my_memcpy(void *, const void *, size_t);

int main(void)
{
	char overwrite_me[]	= "Overwrite me, please!";
	/* using longer string than above will trigger a stack smash */
	char new_string[]	= "New data here.";

	/* check string before memcpy */
	(void)printf("Before memcpy: %s\n", overwrite_me);

	/* run memcpy */
	(void)my_memcpy((void *)overwrite_me, (const void *)new_string,
			sizeof(new_string));

	/* check after memcpy */
	(void)printf("After memcpy: %s\n", overwrite_me);

	return 0;
}

void *my_memcpy(void *str1, const void *str2, size_t n)
{
	/* set pts to start of each string */
	char *to = (char *)str1;
	char *from = (char *)str2;

	/* copy until size counts down */
	while (n-- > 0) {
		*to++ = *from++;
	}
	return str1;
}
