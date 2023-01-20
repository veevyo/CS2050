#include "prelab1.h"

void printArray(int * array, int size);

int main(void) {
	int distinctCount, largest, smallest = 0;
	int array[] = {17, 33, 2, 2, 14, 9, 4};
	getArrayInfo(array, 8, &distinctCount, &largest, &smallest);
	printArray(array, 8);
	printf("Distinct counter is: %d\nLargest num is %d\nSmallest num is %d\n", distinctCount, largest, smallest);
}

void printArray(int * array, int size) {
	int i;
	printf("{");
	for (i = 0; i < size; i++) {
		if (i == size - 1) {
			printf("%d}\n", array[i]);
		}
		else {
			printf("%d, ", array[i]);
		}
	}
}
	