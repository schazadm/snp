#include <assert.h>
#include <string.h>
#include <stdio.h>

#include "person.h"

int person_compare(const person_t *a, const person_t *b)
{
	int res = strncmp(a->name, b->name, NAME_LEN);
	if (res == 0) res = strncmp(a->first_name, b->first_name, NAME_LEN);
	if (res == 0) res = a->age - b->age;
	return res;
}

int person_read(person_t *p)
{
	int amountOfInputs = scanf("%20s %20s %u", p->name, p->first_name, &(p->age));
	return amountOfInputs == 3;
}
