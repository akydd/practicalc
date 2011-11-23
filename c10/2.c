/*
 * define macros for CLEAR_BIT and TEST_BIT
 */

#include <stdio.h>

char graphics[2][10]; /* the graphics data */

#define SET_BIT(x,y) graphics[(x)/8][y] |= (0x80>>((x)%8))
#define CLEAR_BIT(x,y) graphics[(x)/8][y] &= ~(0x80>>((x)%8))
#define TEST_BIT(x,y) ( (graphics[(x)/8][y] & (0x80>>((x)%8))) == (0x80>>((x)%8)) )

void print_graphics(void);
int is_coord_valid(int, int);
void print_menu(void);

int main(void)
{
	char input[10];
	char operation;
	int row;
	int column;
	int result;

	while(1 == 1) {
		/* clear input buffer */
		input[0] = '\0';

		print_menu();

		(void)fgets(input, sizeof(input), stdin);
		result = sscanf(input, "%c %d %d", &operation, &column, &row);

		if (result == 0) {
			(void)printf("Bad input. Try again.\n");
			continue;
		}

		if (operation == 'q') {
			break;
		}

		if (!is_coord_valid(column, row)) {
			(void)printf("Invalid coordinates.  Try again.\n");
			continue;
		}

		switch (operation) {
			case 's':
				SET_BIT(column, row);
				break;
			case 'c':
				CLEAR_BIT(column, row);
				break;
			default:
				(void)printf("Bad operation.  Try again.\n");
		}

		print_graphics();
	}
	return 0;
}

void print_menu(void)
{
	(void)printf("Enter drawing operation followed by coords.\n");
	(void)printf("Valid operations are\n");
	(void)printf("\'s\' to set,\n");
	(void)printf("\'c\' to clear,\n");
	(void)printf("\'q\' to quit.\n");
	(void)printf("Coordinates must be between 0 and 9.\n");
	(void)printf("For example: \'s 3 3\' sets bit (3,3).\n");
}

int is_coord_valid(int x, int y) {
	if ( (x < 0) || (x > 9) || (y < 0) || (y > 9) ) {
		return 0;
	}

	return 1;
}

void print_graphics(void)
{
	int y; /* current y location */
	int bit; /* bit we are testing in current byte */

	for (y = 0; y < 10; y++) {
		/* Handle first 8 bits */
		for (bit = 0x80; bit > 0; bit = (bit >> 1)) {
			if ((graphics[0][y] & bit) != 0) {
				(void)printf("X");
			} else {
				(void)printf(".");
			}
		}

		/* Handle last 2 bits */
		for (bit = 0x80; bit > 32; bit = (bit >> 1)) {
			if ((graphics[1][y] & bit) != 0) {
				(void)printf("X");
			} else {
				(void)printf(".");
			}
		}

		(void)printf("\n");
	}
	(void)printf("\n");
}

