/*
 * =====================================================================================
 *
 *       Filename:  1.c
 *
 *    Description:  calculate the distance between 2 points
 *
 *        Version:  1.0
 *        Created:  11-11-05 04:12:13 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan Kydd (), akydd@ualberta.net
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <math.h>

int main()
{
	float a[2], b[2];
	char input[10];
	float distance;

	printf("Enter the x and y coordinated for point a: ");
	fgets(input, sizeof(input), stdin);
	sscanf(input, "%f %f", a, a+1);

	printf("Enter the x and y coordinate for point b: ");
	fgets(input, sizeof(input), stdin);
	sscanf(input, "%f %f", b, b+1);

	distance = sqrt(pow(a[0]-b[0], 2.0) + pow(a[1]-b[1], 2.0));
	printf("The distance between the points is %f.\n", distance);

	return 0;
}
