#include <stdio.h>

static int char_type(char);

int char_type(char letter)
{
	int i = 0;
	char vowels[] = {'A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u'}; 
	char consonants[] = {'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'M', \
		'N', 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'X', 'Y', 'Z', \
		'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', \
		'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};

	for (i = 0; i < 10; i++) {
		if (letter == vowels[i]) {
			return 1;
		}
	}

	for (i = 0; i < 42; i++) {
		if (letter == consonants[i]) {
			return -1;
		}
	}

	return 0;
}

int main(void)
{
	char input[10];
	char letter;
	int result;
	int char_check;

	while(1 == 1) {
		(void)printf("Enter letter, or non letter to quit: ");
		(void)fgets(input, sizeof(input), stdin);
		result = sscanf(input, "%c", &letter);

		if (result != 1) {
			break;
		}

		char_check = char_type(letter);
		if (char_check == 1) {
			(void)printf("You entered a vowel.\n");
		} else if (char_check == -1) {
			(void)printf("You did not enter a vowel.\n");
		} else {
			(void)printf("You did not enter a letter.  Bye!\n");
			break;
		}
	}

	return 0;
}
