#include <stdio.h>

int main(void)
{
	char input[10];
	int total_minutes;

	printf("Enter total minutes: ");
	fgets(input, sizeof(input), stdin);
	sscanf(input, "%d", &total_minutes);

	printf("%d minutes is equal to %d hours and %d minutes.\n", total_minutes, total_minutes/60, total_minutes%60);

	return 0;
}
