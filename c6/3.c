#include <stdio.h>

#ifndef CHAR_BIT
#define CHAR_BIT 8.0
#endif

int size;
int size_unit;
int time_unit;

int main(void)
{
	const long double bits_per_sec = 960.0 * CHAR_BIT;

	long double time_in_secs;
	long double converted_time;
	long double size_in_bits;

	/* Set the filesize, size units, and time units	 */
	set_filesize();
	set_size_unit();
	set_time_unit();

	/* convert filesize to bits */
	size_in_bits = (long double)size_to_bits();

	if (size_in_bits != -1) {
		(void)printf("Size in bits is %10.2Lf.\n", size_in_bits);
		(void)printf("2: size_in_bits is %l.\n", size_to_bits());
		/* time to process, in seconds */
		time_in_secs = size_in_bits / bits_per_sec;

		/* convert the time.  If valid, print it out. */
		converted_time = convert_time(time_in_secs);
		if (converted_time != -1) {
			(void)printf("Total time is %Lf.\n", converted_time);
		} else {
			(void)printf("Correct errors and try again.\n");
		}
	}

	return 0;
}

long double convert_time(long double seconds)
{
	long double time = -1;

	if (time_unit == 1) {
		time = seconds;
	} else if (time_unit == 2) {
		time = time / 60.0;
	} else if (time_unit == 3) {
		time = (time / 60.0) / 60.0;
	} else if (time_unit == 4) {
		time = ((time / 60.0) / 60.0) / 24.0;
	} else {
		(void)printf("Invalid time unit!\n");
	}

	return time;
}

long double size_to_bits(void)
{
	long double size_in_bits = -1;

	if (size_unit == 1) {
		size_in_bits = (long double)size;
	} else if (size_unit == 2) {
		size_in_bits = (long double)size * 8;
	} else if (size_unit == 3) {
		size_in_bits = (long double)size * 8 * 1048576;
	} else {
		(void)printf("Invalid size unit!\n");
	}

	(void)printf("size_in_bits is %Lf.\n", size_in_bits);
	return (size_in_bits);
}

void set_filesize(void)
{
	char str[10];
	int result;

	do {
		(void)printf("Enter size: ");
		fgets(str, sizeof(str), stdin);
		result = sscanf(str, "%d", &size);
	} while (result != 1);
}

void set_size_unit(void)
{
	char str[10];
	int result;

	do {
		(void)printf("Choose units:\n");
		(void)printf(" 1. bits\n");
		(void)printf(" 2. bytes\n");
		(void)printf(" 3. megabytes\n");
		fgets(str, sizeof(str), stdin);
		result = sscanf(str, "%d", &size_unit);
	} while (result != 1);
}

void set_time_unit(void)
{
	char str[10];
	int result;

	do {
		(void)printf("Choose time unit:\n");
		(void)printf(" 1. seconds\n");
		(void)printf(" 2. minutes\n");
		(void)printf(" 3. hours\n");
		(void)printf(" 4. days\n");
		fgets(str, sizeof(str), stdin);
		result = sscanf(str, "%d", &time_unit);
	} while (result != 1);
}
