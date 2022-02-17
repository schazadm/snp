/**
 *  P02 Praktikum
 *
 *  - Funktionen
 *  - Funktion Schaltjahr 
 *  - Funktion Tage pro Monat  
 *  - Funktion Wochentag
 * 
 *  @author ZHAW
 *  @version 1.0 - 08.02.2022
 */

#include <stdio.h>
#include <stdlib.h>


int leseZahl(char *prompt, int min, int max) { 		// Datentyp angeben, Parameter angeben 
	char zahlString[11];
	int zahl;
	
	do {
		printf("%s", prompt);
		fgets(zahlString, 10, stdin);
		zahl = atoi(zahlString); // bei ungueltiger Zahl return 0
  	} while ((zahl < min) || (zahl > max));
	return zahl;			 // return Zeile angeben
}

/**

____ leseZahl(____) { 		// Datentyp angeben, Parameter angeben 
	char zahlString[11];
	int zahl;
	
	fgets(zahlString, 10, stdin);
	zahl = atoi(zahlString); // bei ungueltiger Zahl return 0
	___________________		// return Zeile angeben

}
*/



/* Konstante Werte fuer die Monate */
enum { JAN=1, FEB, MAR, APR, MAI, JUN, JUL, AUG, SEP, OKT, NOV, DEZ };


int main (void) {

    // 
    //  Variablen definieren 
    //
    int monat, jahr;
    char *prompt;
        
    int istSchaltjahr = 0;       // 0: kein Schaltjahr, sonst Schaltjahr
    int tageProMonat = 0;        // Ergebnis spaeter in dieser Variablen

    
    //
    //  Monat und Jahr einlesen
    //
    
    //printf("Monat:     ");
	//scanf("%d", &monat);
    //printf("Jahr:      ");  
    //scanf("%d", &jahr);

    prompt = "Monat: ";     
    monat = leseZahl(prompt, 1, 12);
    prompt = "Jahr:  ";     
    jahr = leseZahl(prompt, 1, 3000);

    //  Ausgabe zum Test
    //  printf("Monat: %d, Jahr: %d \n", monat, jahr);    

    
    //
    //  Monate mit 30 und 31 Tagen behandeln
    //
    switch (monat) {
        
    case JAN: case MAR: case MAI: case JUL: case AUG: case OKT: case DEZ:
        tageProMonat = 31;
        break;
        
    case APR: case JUN: case SEP: case NOV:            
        tageProMonat = 30;
        break;
    
    //
    //  Monat ist 2: Auf Schaltjahr ueberpruefen
    //
    case FEB:
        if (jahr % 4 == 0 && (jahr % 100 != 0 || jahr % 400 == 0)) {
            tageProMonat = 29;
        }
        else {
            tageProMonat = 28;
        }
        break;
    
    //
    //  Anderer Monat: Fehler
    //
    default:
        printf("Der Monat muss zwischen 1 und 12 sein.\n");
        return 1;
    }
    
    //
    //  Ergebnis ausgeben
    //
    printf("Der Monat %d.%d hat %d Tage.\n", monat, jahr, tageProMonat);
 
    return 0;   
}
