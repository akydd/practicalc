#include <stdio.h>

#ifndef CHAR_BIT
#define CHAR_BIT 8
#endif

static int size;
static int size_unit;
static int time_unit;

static void set_filesize(void);
static void set_size_unit(void);
static void set_time_unit(void);
static float convert_time(float);
static float size_to_bits(void);

int main(void)
{
	const float bits_per_sec = (float)(960.0 * CHAR_BIT);

	float time_in_secs;
	float converted_time;
	float size_in_bits;

	/* Set the filesize, size units, and time units	 */
	set_filesize();
	set_size_unit();
	set_time_unit();

	/* convert filesize to bits */
	size_in_bits = size_to_bits();

	if (size_in_bits != -1) {
		/* time to process, in seconds */
		time_in_secs = size_in_bits / bits_per_sec;

		/* convert the time.  If valid, print it out. */
		converted_time = convert_time(time_in_secs);
		if (converted_time != -1) {
			(void)printf("Total time is %f.\n", converted_time);
		} else {
			(void)printf("Correct a valid time and try again.\n");
		}
	} else {
		(void)printf("Choose a valid size and try again.\n");
	}

	return 0;
}

float convert_time(float seconds)
{
	float time = -1;

	if (time_unit == 1) {
		time = seconds;
	} else if (time_unit == 2) {
		time = (float)(seconds / 60);
	} else if (time_unit == 3) {
		time = (float)((seconds / 60.0) / 60.0);
	} else if (time_unit == 4) {
		time = (float)(((seconds / 60.0) / 60.0) / 24.0);
	} else {
		(void)printf("Invalid time unit!\n");
	}

	return time;
}

float size_to_bits(void)
{
	float size_in_bits = -1;

	/*  we only like non negative sizes */
	if (size >= 0) {
		if (size_unit == 1) {
			size_in_bits = (float)size;
		} else if (size_unit == 2) {
			size_in_bits = (float)size * 8;
		} else if (size_unit == 3) {
			size_in_bits = (float)size * 8 * 1048576;
		} else {
			(void)printf("Invalid size unit!\n");
		}
	}

	return size_in_bits;
}

void set_filesize(void)
{
	char str[10];
	int result;

	do {
		(void)printf("Enter size: ");
		(void)fgets(str, sizeof(str), stdin);
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
		(void)fgets(str, sizeof(str), stdin);
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
		(void)fgets(str, sizeof(str), stdin);
		result = sscanf(str, "%d", &time_unit);
	} while (result != 1);
}
