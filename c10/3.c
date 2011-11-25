/*
 * Draw a white line across a black background.
 * Not sure what the author wants here.
 */

#include <stdio.h>

#define X_SIZE 16 /* size of array in X direction */
#define Y_SIZE 16 /* size of array in Y direction */

static char graphics[X_SIZE / 8][Y_SIZE]; /* the graphics data */

#define SET_BIT(x,y) graphics[(x)/8][y] |= (0x80>>((x)%8))
#define CLEAR_BIT(x,y) graphics[(x)/8][y] &= ~(0x80>>((x)%8))
#define TEST_BIT(x,y) ( (graphics[(x)/8][y] & (0x80>>((x)%8))) == (0x80>>((x)%8)) )

static void print_graphics(void);

int main(void)
{
	int loc;

	/* draw a horizontal line approx halfway down */
	for (loc = 0; loc < X_SIZE; loc++) {
		SET_BIT(loc, Y_SIZE / 2);
	}
	print_graphics();

	return 0;
}

void print_graphics(void)
{
	int x; /* current x BYTE */
	int y; /* current y location */
	int bit; /* bit we are testing in current byte */

	for (y = 0; y < Y_SIZE; ++y) {
		/* Loop for each byte in the array */
		for (x = 0; x < X_SIZE / 8; ++x) {
			/* Handle each bit */
			for (bit = 0x80; bit > 0; bit = (bit >> 1)) {
				if ((int)(graphics[x][y] & bit) != 0) {
					(void)printf("_");
				} else {
					(void)printf(" ");
				}
			}
		}
		(void)printf("\n");
	}
	(void)printf("\n");
}

