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

int readInput() {
	return getchar();
}

/**
 * @brief Main entry point.
 * @param[in] argc  The size of the argv array.
 * @param[in] argv  The command line arguments...
 * @returns Returns EXIT_SUCCESS (=0) on success, EXIT_FAILURE (=1) there is an expression syntax error.
 */
int main(int argc, char* argv[])
{
	// BEGIN-STUDENTS-TO-ADD-CODE

	list_init();
	person_t p;
	int loop = 1;
	printf("I(nsert), R(emove), S(how), C(lear), E(nd)\n\n");
	while(loop) {
		printf("Input: ");
		int input = readInput();
		
		switch(input) {
			case 'I':
			case 'i':
				if (!person_read(&p) || !list_insert(&p)) {
					printf("failed to insert person\n");
				}
				break;
			case 'R':
			case 'r':
				if (!person_read(&p) || !list_remove(&p)) {
					printf("failed to remove person\n");
				}
				break;
			case 'S':
			case 's':
				list_show();
				break;
			case 'C':
			case 'c':
				list_clear();
				break;
			case EOF:
			case 'E':
			case 'e':
				loop = 0;
				break;
			case ' ': 
			case '\n':
				break;
			default:
				printf("Unknown command: %c\n", input);
				break;
		}
	}

	// END-STUDENTS-TO-ADD-CODE
	return EXIT_SUCCESS;
}

