#include <stdio.h>

int main(void)
{
	char input[10];
	float hours, minutes;

	printf("Enter hours and minutes: ");
	fgets(input, sizeof(input), stdin);
	sscanf(input, "%f %f", &hours, &minutes);

	printf("There are a total of %f minutes.\n", 60*hours + minutes);

	return 0;
}
