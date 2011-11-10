#include <stdio.h>
#define WIDTH 5
#define HEIGHT 3
#define SIZE 2

int main(void)
{
	int x;
	int y;

	for (y = 0; y <= SIZE * (HEIGHT + 1); y++) {	

		for (x = 0; x <= SIZE * (WIDTH + 1); x++) {

			if ( ( x % (WIDTH + 1) == 0 ) &&
					( y % (HEIGHT + 1) == 0 ) ) {
				/* non-ending corner pieces */
				(void)printf("+");
				break
			} else if ( ( x % (SIZE * (WIDTH + 1) ) == 0 ) &&
					( y % (HEIGHT + 1) == 0 ) ) {
				/* ending corner pieces */
				(void)printf("+\n");
				break;
			} else if ( () && () ) {
				/* spaces */
				(void)printf(" ");
				break;
			} else if () {
				/* non-ending vertical bars */
				(void)printf("|");
				break;
			} else if () {
				/* ending vertical bars */
				(void)printf("|\n");
				break;
			} else if () {
				/* horizontal bars */
				(void)printf("-");
			}
		}
	}

	return 0;
}
