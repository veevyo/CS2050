#include "lab1.h"

void printArray(int * array, int size);

int main(void) {
	int array[] = {1,2,3,4,5,6,7,8};
	int size = sizeof(array) / sizeof(array[0]);
	float average = 0;
	int evenSum = 0;
	int errorCheck1 = getAverage(array, size, &average);
	int errorCheck2 = sumEven(array, size, &evenSum);
	printArray(array, size);
	if (errorCheck1 == 0) {
		printf("The average was %f\n", average);
	}
	if (errorCheck2 == 0) {
		printf("The sum of even values was %d\n", evenSum);
	}
	
}

void printArray(int * array, int size) {
	int i;
	printf("{");
	for (i = 0; i < size; i++) {
		if (i == size - 1) {
			printf("%d}",array[i]);
		}
		else {
			printf("%d, ", array[i]);
		}
	}
	printf("\n");
}
