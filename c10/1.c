/*
 * define macros for CLEAR_BIT and TEST_BIT
 */

#include <stdio.h>

#define X_SIZE 16 /* size of array in X direction */
#define Y_SIZE 16 /* size of array in Y direction */

char graphics[X_SIZE / 8][Y_SIZE]; /* the graphics data */

#define SET_BIT(x,y) graphics[(x)/8][y] |= (0x80>>((x)%8))
#define CLEAR_BIT(x,y) graphics[(x)/8][y] &= ~(0x80>>((x)%8))
#define TEST_BIT(x,y) ( (graphics[(x)/8][y] & (0x80>>((x)%8))) == (0x80>>((x)%8)) )

void print_graphics(void);

int main(void)
{
	int loc;

	/* set diagonal */
	for (loc = 0; loc < X_SIZE; loc++) {
		SET_BIT(loc, loc);
	}
	print_graphics();

	/* test SET_BIT */
	SET_BIT(2,3);
	print_graphics();

	/* test CLEAR_BIT */
	CLEAR_BIT(2,2);
	CLEAR_BIT(4,2);
	print_graphics();

	if (TEST_BIT(2,3)) {
		(void)printf("TEST_BIT for set bit ok.\n");
	} else {
		(void)printf("TEST_BIT for set bit not ok.\n");
	}

	if(!TEST_BIT(2,2)) {
		(void)printf("TEST_BIT for unset bit ok.\n");
	} else {
		(void)printf("TEST_BIT for unset bit not ok.\n");
	}

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
				if ((graphics[x][y] & bit) != 0) {
					(void)printf("X");
				} else {
					(void)printf(".");
				}
			}
		}
		(void)printf("\n");
	}
	(void)printf("\n");
}

