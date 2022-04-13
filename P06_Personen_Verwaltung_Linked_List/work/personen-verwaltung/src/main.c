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
#include <stdlib.h>
#include "person.h"
#include "list.h"

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define RESET "\x1B[0m"

int readInput() {
    int input = getchar();
    clear_buffer();
    return input;
}

/**
 * @brief Main entry point.
 * @param[in] argc  The size of the argv array.
 * @param[in] argv  The command line arguments...
 * @returns Returns EXIT_SUCCESS (=0) on success, EXIT_FAILURE (=1) there is an expression syntax error.
 */
int main(int argc, char *argv[]) {
    // BEGIN-STUDENTS-TO-ADD-CODE
    list_init();
    person_t p;
    int loop = 1;
    printf(GRN "**Available Commands**\n" RESET);
    printf(YEL "I(nsert), R(emove), S(how), C(lear), E(nd)\n\n" RESET);
    while (loop) {
        printf(GRN "Ready for Command: " RESET);
        int input = readInput();
        switch (input) {
            case 'I':
            case 'i':
                printf(YEL "I(nsert)\n" RESET);
                if (!person_read(&p) || !list_insert(&p)) {
                    printf(RED "failed to insert person\n" RESET);
                }
                break;
            case 'R':
            case 'r':
                printf(YEL "R(emove)\n" RESET);
                if (!person_read(&p) || !list_remove(&p)) {
                    printf(RED "failed to remove person\n" RESET);
                }
                break;
            case 'S':
            case 's':
                printf(YEL "S(how)\n" RESET);
                list_show();
                break;
            case 'C':
            case 'c':
                printf(YEL "C(lear)\n" RESET);
                list_clear();
                break;
            case EOF:
            case 'E':
            case 'e':
                printf(YEL "E(nd)\n" RESET);
                loop = 0;
                break;
            default:
                printf(RED "Unknown command: %c\n" RESET, input);
                break;
        }
    }
    // END-STUDENTS-TO-ADD-CODE
    return EXIT_SUCCESS;
}
