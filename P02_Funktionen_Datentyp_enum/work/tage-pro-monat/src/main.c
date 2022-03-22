/**
 *  P02 Praktikum
 *
 *  Das Programm liest einen Monat (1-12) und ein Jahr (1600-2400) ein und
 *  gibt die Anzahl der Tage dieses Monats aus.
 *
 *  @author Gerrit Burkert, Adaptation bazz
 *  @version 15-FEB-2013, 16-OCT-2017, 17-OCT-2019, 16-FEB-2022
 */

#include <stdio.h>
#include <stdlib.h>

#define ERROR_IN_MONTH 1
#define ERROR_IN_YEAR 2

enum Monate {
	JAN = 1, FEB, MAR, APR, MAI, JUN, JUL, AUG, SEP, OKT, NOV, DEZ
};

int gibIntWert(char type[], int min, int max);

int istSchaltjahr(int jahr);

int tageProMonat(int jahr, int monat);

int main (int argc, char *argv[]) {

	int monat, jahr;

	//  Monat einlesen und Bereich ueberpruefen
	monat = gibIntWert("Monat", 1, 12);
	jahr  = gibIntWert("Jahr", 1600, 9999);

	//  Ausgabe zum Test
	printf("Monat: %d, Jahr: %d \n", monat, jahr);    

	//  Ausgabe zum Test (hier mit dem ternaeren Operator "?:")
	printf("%d ist %s Schaltjahr\n", jahr, istSchaltjahr(jahr) ? "ein" : "kein");

	// Ausgabe
	printf("Der Monat %02d-%d hat %d Tage.\n", monat, jahr, tageProMonat(jahr, monat));

	return 0;
}

int gibIntWert(char type[], int min, int max) {
	printf("Please enter the %s, min: %d max: %d: ", type, min, max);
	int input;
	scanf("%d", &input);
	if (input < min || input > max) {
		printf("Invalid Value for %s\n", type);
		return gibIntWert(type, min, max);
	}
	return input;
}

int istSchaltjahr(int jahr) {
	int istSchaltjahr = 0;
	if (jahr % 4 == 0) {
		istSchaltjahr = 1;
		if (jahr % 100 == 0) {
			istSchaltjahr = 0;
			if (jahr % 400 == 0) {
				istSchaltjahr = 1;
			}
		}
	}
	return istSchaltjahr;
}

int tageProMonat(int jahr, int monat) {
	switch (monat) {
		case JAN:
		case MAR:
		case MAI:
		case JUL:
		case AUG:
		case OKT:
		case DEZ:
			return 31;
		case APR:
		case JUN:
		case SEP:
		case NOV:
			return 30;
		case FEB:
			return istSchaltjahr(jahr) ? 29 : 28;
		default:
			printf("Der Monat ist invalid!\n");
			return -1;
	}
}

