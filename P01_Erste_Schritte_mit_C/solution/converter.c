/* ----------------------------------------------------------------------------
 * --  _____       ______  _____                                              -
 * -- |_   _|     |  ____|/ ____|                                             -
 * --   | |  _ __ | |__  | (___    Institute of Embedded Systems              -
 * --   | | | '_ \|  __|  \___ \   Zuercher Hochschule Winterthur             -
 * --  _| |_| | | | |____ ____) |  (University of Applied Sciences)           -
 * -- |_____|_| |_|______|_____/   8401 Winterthur, Switzerland               -
 * ----------------------------------------------------------------------------
 */
/**
 * @file
 * @brief Lab implementation
 */
#include <stdio.h>
#include <stdint.h>

#define ROW_COUNT 8

/**
 * @brief Main entry point.
 * @param[in] argc  The size of the argv array.
 * @param[in] argv  The command line arguments...
 * @returns Returns EXIT_SUCCESS (=0) on success, EXIT_FAILURE (=1) if there is an input error.
 */
int main(char argc, char* argv){
    uint16_t i;
    double rate;

    printf("Umwandlungskurs eingeben (1.00 BTC -> CHF): ");
    if (1!= scanf("%lf", &rate)){
        printf("Ungültige Eingabe! Geben Sie eine Fliesskommazahl ein.\n");
        return 1;
    }

    for(i = 1; i <= ROW_COUNT; i++) {
        printf("%5d CHF\t<-->\t %5.5lf BTC\n", i*200, (double)i*200/rate);
    }
    return 0;
}