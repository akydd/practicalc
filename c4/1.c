#include <stdio.h>

int main(void)
{
	char input[5];
	float degrees_c;

	printf("Enter degrees centigrade: ");
	fgets(input, sizeof(input), stdin);
	sscanf(input, "%f", &degrees_c);
	printf("%f centigrade is equal to %f fahrenheit.\n", degrees_c, (9*degrees_c)/5+32);

	return 0;
}
