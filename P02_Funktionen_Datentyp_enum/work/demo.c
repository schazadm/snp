#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

/** Aufgabe 1:
enum Typ "textFlags" deklarieren mit den einzelnene Werten
- ITALICS   = 00000001  // = 1
- BOLD      = 00000010  // = 2
- UNDERLINE = 00000100  // = 4
*/

enum textFlags { ITALICS = 1, BOLD = 2, UNDERLINE = 4 };

/** Aufgabe 2
Funktion Flag Einlesen
*/

void menu (void) {
	(void) printf("\nBitte geben Sie die gewuenschten Flags ein\n");
	(void) printf("(Ugueltige Eingaben fuehren zum Abbruch.)\n");
	(void) printf("Kursiv:        tippen Sie die 1\n");
	(void) printf("Fett:          tippen Sie die 2\n");
	(void) printf("Unterstrichen: tippen Sie die 3\n");
	(void) printf("Abbrechen:     tippen Sie die 0\n");
	(void) printf("Ihre Wahl: ");
}


int flagEinlesen() {
	fflush(stdin);
	int flag = fgetc(stdin) - '0';
	if (flag < 1 || flag > 3) { flag = 0; } 
	return flag;
}


void displayFlags(int flags) {
	printf("Gesetzte Flags: %d\n", flags);
}

/** Vorgegebener Programm-Rumpf */
int main(void) {
	int oneFlag, flags = 0; 
	do {
		menu();
		oneFlag = flagEinlesen();
		switch (oneFlag) {
			case 1:
				printf("Wahl: 1, Flag: %d", oneFlag);
				flags |= ITALICS;
				break;
			case 2:
				printf("Wahl: 2, Flag: %d", oneFlag);
				flags |= BOLD;
				break;
			case 3:
				printf("Wahl: 3, Flag: %d", oneFlag);
				flags |= UNDERLINE;
				break;
		}
		(void) displayFlags(flags);
	} while (oneFlag != 0);
}

