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

/**
 * @brief Main entry point.
 * @param[in] argc  The size of the argv array.
 * @param[in] argv  The command line arguments...
 * @returns Returns EXIT_SUCCESS (=0) on success, EXIT_FAILURE (=1) there is an expression syntax error.
 */
int main(char argc, char* argv[]) {
    uint16_t char_count = 0, word_count = 0;
    char c;
    uint8_t is_word = 0;

    printf("Eingabe: ");
    c=getchar();
    while('\n' != c){
        char_count++;
        if(c != ' ' && c !='\t'){
            if(! is_word){
                is_word = 1;
                word_count++;
            }
        } else {
            is_word = 0;
        }
        c = getchar();
    }

    printf("%d Zeichen, %d W\u00F6rter\n", char_count, word_count);
    return 0;
    

}