#include <string.h>
#include <stdio.h>
#include "person.h"

int person_compare(const person_t *a, const person_t *b) {
    if (a == NULL || b == NULL)
        return 0;

    int res = strncmp(a->name, b->name, NAME_LEN);
    if (res == 0)
        res = strncmp(a->first_name, b->first_name, NAME_LEN);
    if (res == 0)
        res = a->age - b->age;

    return res;
}

int person_read(person_t *p) {
    if (p == NULL)
        return 0;
    int readInputs = scanf("%19s %19s %u", p->name, p->first_name, &(p->age));
    clear_buffer();
    return readInputs == 3;
}

void clear_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}
