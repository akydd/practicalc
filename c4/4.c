#include <stdio.h>

int main(void)
{
	char input[10];
	float miles;

	printf("Enter speed in miles (per hour): ");
	fgets(input, sizeof(input), stdin);
	sscanf(input, "%f", &miles);
	printf("%f miles/hr is equal to %f kilometers/hr.\n", miles, miles/0.6213712);

	return 0;
}	
