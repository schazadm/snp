
# Lösungsskizzen
## Aufgabe 1
```
/**
 *  Tage Pro Monat
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

///// Student Code



// Konstante Werte fuer die Monate
// ===============================

enum { JAN=1, FEB, MAR, APR, MAI, JUN, JUL, AUG, SEP, OKT, NOV, DEZ };


// Eingabe pruefen (0 ist vom atoi als Fehelcode verwendet und darf nicht verwendet werden) 
// ===============

int gibIntWert(char *name, int von, int bis) {
	
	int wert;
	char wertS[20]; //
	
	do {
    	printf("%s:     ", name);
    	fgets(wertS, 20, stdin);
    	wert = atoi(wertS);
    	if (wert < von || wert > bis) {
        	printf("Der Wert muss zwischen %d und %d sein.\n", von, bis);
    	} else {
    		break; 
		}
	} while(1);
	return wert;
}


// Schaltjahr bestimmen
// ==================== 

int istSchaltjahr(int jahr){
	
	if ( (jahr % 400 == 0) || ( (jahr %100 != 0) && (jahr % 4 ==0) ) )
		return 1;
	else
		return 0;
}


// Berechnung Anzahl Tage pro Monat
// ================================

int tageProMonat(int jahr, int monat) {

	int anzTage;
    
    // Tage pro Monat bestimmen
    switch (monat) {
	   
        // Monate mit 31 Tagen 
        case JAN: case MAR: case MAI: case JUL: case AUG: case OKT: case DEZ:
            anzTage = 31;
            break;
        
        // Monate mit 30 Tagen 
        case APR: case JUN: case SEP: case NOV:
            anzTage = 30;
            break;
        
        // Februar: 28 oder 29 Tage 
        case FEB:
		
            if (istSchaltjahr(jahr)) {
                anzTage = 29;
            } else {
                anzTage = 28;
            }
            break;
    }

	return anzTage;
}

///// END Student Code


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

```
## Aufgabe 2
Alter bestehender Boilerplate Code

