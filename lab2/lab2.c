#include "lab2.h"

/*accepts a pointer to an int array and its size; uses malloc to allocate memory to the array. returns 1 if malloc fails, returns 0 on array created successfully*/
int makeArray(int ** array, int size) {
	*array = malloc(size * sizeof(int));
	if (*array == NULL) {
		return 1;
	}
	return 0;
}

/*accepts an int array and its size; fills the array with 0s*/
void initArray (int * array , int size ) {
	int i;
	for (i = 0; i < size; i++) {
		array[i] = 0;
	}
}

/*accepts an int array, the size of the array and a number to multiply by; the function goes through the given array and mutliplies only positive elements by the given multiplicand, returning the number of elements affected by this change as an int*/
int multiplyPositive (int * array , int size , int multiplicand ) {
	int i;
	int multipliedElements = 0;
	for (i = 0; i < size; i++) {
		if (array[i] > 0) {
			array[i] = array[i] * multiplicand;
			multipliedElements++;
		}
	}
	return multipliedElements;
}

/*accepts pointer to an int array, frees array, sets array and its ptr to NULL*/
void freeArray (int ** array ) {
	free(*array);
	*array = NULL;
	array = NULL;
}
