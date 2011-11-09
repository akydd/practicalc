#include <stdio.h>

int main(void)
{
	int pos_nums = 0;
	int neg_nums = 0;
	int result;

	do {
		char input[10];
		int x;

		(void)printf("Enter a number (non number to quit): ");
		(void)fgets(input, sizeof(input), stdin);
		result = sscanf(input, "%d", &x);

		if (result == 1) {
			if (x < 0) {
				neg_nums++;
			} else if (x > 0) {
				pos_nums++;
			}
		}

	} while (result == 1);

	(void)printf("There are %d positive numbers.\n", pos_nums);
	(void)printf("There are %d negative numbers.\n", neg_nums);

	return 0;
}
