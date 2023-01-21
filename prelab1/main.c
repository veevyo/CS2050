#include "prelab1.h"

//used for testing
void printArray(int * array, int size);

int main(void) {
	//test values, feel free to change
	int distinctCount, largest, smallest = 0;
	int array[] = {3, 2, 1, 0, 0, 0, 22, 2};
	int size = sizeof(array) / sizeof(array[0]);
	getArrayInfo(array, size, &distinctCount, &largest, &smallest);
	printArray(array, size);
	printf("Distinct counter is: %d\nLargest num is %d\nSmallest num is %d\n", distinctCount, largest, smallest);
}

//print arr for testing purposes in the console
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
	
