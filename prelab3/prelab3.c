#include "prelab3.h"

void * createArray(int size, int type) {
	int * array = malloc((size * type) + type);
	array[0] = size;
	return (void *) array;
}

int getArraySize(void * array) {
	int * intarray = (int *)array;
	return intarray[0];
}

void freeArray(void ** array) {
	free(*array);
	*array = NULL;
}
