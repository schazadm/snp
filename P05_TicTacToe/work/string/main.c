#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NUMBER_OF_WORDS 10
#define MAX_NUMBER_OF_CHARS 21

/**
 * Reads an user string input of max length 20 chars
 *
 * @param arrayPtr Pointer to where it should save the input
 */
void readWord(char *arrayPtr) {
	// read char by char
	/*
	   const char SPACE = ' ';
	   const char TAB = '\t';
	   const char EOL = '\n';
	   int charCount = 0;
	   char character = (char) getchar();
	   while (charCount < MAX_NUMBER_OF_CHARS) {
	   if (character == SPACE || character == EOL || character == TAB)
	   break;
	   arrayPtr[charCount] = character;
	   charCount++;
	   character = (char) getchar();
	   }
	   */
	   
	// let scanf read string
	scanf("%20s", arrayPtr);
}

/**
 * Receives a pointer to an array and transforms every element into an upper-case
 *
 * @param arrayPtr Pointer of array to format
 */
void formatToUpperCase(char *arrayPtr) {
	for (int i = 0; i < strlen(arrayPtr); i++) {
		arrayPtr[i] = (char) toupper(arrayPtr[i]);
	}
}

/**
 * Receives a 2D-Array and investigates its values with strcmp and returns 1 if a string already exists
 *
 * @param array Array to investigate
 * @param rowCount Amount of rows which are filled
 * @return 0 if not exist, 1 if exist
 */
int wordAlreadyExists(char array[MAX_NUMBER_OF_WORDS][MAX_NUMBER_OF_CHARS], int rowCount) {
	for (int i = 0; i < rowCount; i++) {
		for (int j = i + 1; j <= rowCount; j++) {
			if (strcmp(array[i], array[j]) == 0)
				return 1;
		}
	}
	return 0;
}

/**
 * Receives a 2D-Array and sorts its values with strcmp
 *
 * @param array Array to sort
 * @param rowCount Amount of rows which are filled
 */
void sortArray(char array[MAX_NUMBER_OF_WORDS][MAX_NUMBER_OF_CHARS], int rowCount) {
	char temp[MAX_NUMBER_OF_CHARS];
	for (int i = 0; i < rowCount; i++) {
		for (int j = i + 1; j <= rowCount; j++) {
			if (strcmp(array[i], array[j]) > 0) {
				strcpy(temp, array[i]);
				strcpy(array[i], array[j]);
				strcpy(array[j], temp);
			}
		}
	}
}

int main() {
	char word[MAX_NUMBER_OF_WORDS][MAX_NUMBER_OF_CHARS] = {'\0'};
	int wordCounter = 0;

	printf("Enter words: ");

	do {
		readWord(word[wordCounter]);
		formatToUpperCase(word[wordCounter]);

		// break condition - if ZZZ was the last word then break
		if (strlen(word[wordCounter]) == 3
				&& word[wordCounter][0] == 'Z'
				&& word[wordCounter][1] == 'Z'
				&& word[wordCounter][2] == 'Z')
			break;
			
		// continue condition - if a word is already in the array skip
		if (wordAlreadyExists(word, wordCounter))
			continue;

		wordCounter++;
	} while (wordCounter < MAX_NUMBER_OF_WORDS);

	sortArray(word, wordCounter);

	printf("\nPrint of given words: \n");
	for (int i = 0; i < wordCounter; i++) {
		printf("%s\n", word[i]);
	}

	return EXIT_SUCCESS;
}


