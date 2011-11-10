#include <stdio.h>
#define WIDTH 5
#define HEIGHT 3
#define SIZE 8 

int main(void)
{
	int x;
	int y;

	for (y = 0; y <= SIZE * (HEIGHT + 1); y++) {	

		for (x = 0; x <= SIZE * (WIDTH + 1); x++) {

			if ( x % (WIDTH + 1) == 0 ) {

				if ( y % (HEIGHT + 1) == 0 ) {
					(void)printf("+");
				} else {
					(void)printf("|");
				}

				if (x == SIZE * (WIDTH + 1)) {
					(void)printf("\n");
				}

			} else {

				if ( y % (HEIGHT + 1) == 0 ) {
					(void)printf("-");;
				} else {
					(void)printf(" ");
				}
			}
		}
	}

	return 0;
}
