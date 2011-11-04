#include <stdio.h>

int main(void)
{
	char input[5];
	float radius;

	printf("Enter the radius of a sphere: ");
	fgets(input, sizeof(input), stdin);
	sscanf(input, "%f", &radius);
	printf("The volume of the sphere is %f.\n", 4*3.14*radius*radius*radius/3);

	return 0;
}	
