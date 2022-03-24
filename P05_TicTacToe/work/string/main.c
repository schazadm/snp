#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NUMBER_OF_WORDS 10
#define MAX_NUMBER_OF_CHARS 21

void readWord(char *arrayPtr);

void formatToUpperCase(char *arrayPtr);

void sortArray(char *arrayPtr, int numberOfWords);

int main() {
	char word[MAX_NUMBER_OF_WORDS][MAX_NUMBER_OF_CHARS];
	int amountOfGivenWords = 0;
	printf("Enter words: ");
	for (int i = 0; i < MAX_NUMBER_OF_WORDS; i++) {
		readWord(word[i]);
		amountOfGivenWords++;
		formatToUpperCase(word[i]);
		if (strlen(word[i]) == 3 && word[i][0] == 'Z' && word[i][1] == 'Z' && word[i][2] == 'Z')
			break;
	}
	// sortArray((char *) word, amountOfGivenWords);

	char temp[MAX_NUMBER_OF_CHARS];
	for (int i = 0; i <= amountOfGivenWords; i++) {
	    for (int j = i + 1; j <= amountOfGivenWords; j++) {
	        if (strcmp(word[i], word[j]) > 0) {
	            strcpy(temp, word[i]);
	            strcpy(word[i], word[j]);
	            strcpy(word[j], temp);
	        }
	    }
	}

	printf("Print of given words: \n");
	for (int i = 0; i < amountOfGivenWords; i++) {
		printf("%s\n", word[i]);
	}
	return EXIT_SUCCESS;
}

void readWord(char *arrayPtr) {
	scanf("%20s", arrayPtr);
}

void formatToUpperCase(char *arrayPtr) {
	for (int i = 0; i < strlen(arrayPtr); i++) {
		arrayPtr[i] = (char) toupper(arrayPtr[i]);
	}
}

void sortArray(char *arrayPtr, int numberOfWords) {
	char temp[MAX_NUMBER_OF_CHARS];
	for (int i = 0; i <= numberOfWords; i++) {
		for (int j = i + 1; j <= numberOfWords; j++) {
			if (strcmp(&arrayPtr[i], &arrayPtr[j]) > 0) {
				strcpy(temp, &arrayPtr[i]);
				strcpy(&arrayPtr[i], &arrayPtr[j]);
				strcpy(&arrayPtr[j], temp);
			}
		}
	}
}

