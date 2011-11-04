#include <stdio.h>

int main(void)
{
	char input[10];
	float height, width;

	printf("Enter the height and width of the rectangle: ");
	fgets(input, sizeof(input), stdin);
	sscanf(input, "%f %f", &height, &width);
	printf("The perimeter of the rectangle is %f.\n", 2*(width+height));

	return 0;
}
