#include "lab2.h"

void printIntArray(int * array, int size);

int main(void) {
	int size = 7;
	int * array;
	makeArray(&array, size);
	initArray(array, size);
	printf("The array after initialization is: ");
	printIntArray(array, size);
	array[0] = -3;
	array[1] = 1;
	array[3] = 7;
	array[5] = 12;
	array[6] = -40;
	printf("The array after I added some values to it is: ");
	printIntArray(array, size);
	int positiveElements = multiplyPositive(array, size, 2);
	printf("The array after all positive elements are multiplied by two is: ");
	printIntArray(array, size);
	printf("The number of elements multiplied by two was: %d\n", positiveElements);
	int ** arrptr = &array;
	freeArray(arrptr);
	if (array == NULL) {
		printf("Array freed successfully\n");
	}

}

void printIntArray(int * array, int size) {
	int i;
	printf("{");
	for (i = 0; i < size; i++) {
		if (i == size - 1) {
			printf("%d}\n",array[i]);
		}
		else {
			printf("%d, ",array[i]);
		}
	}
}
