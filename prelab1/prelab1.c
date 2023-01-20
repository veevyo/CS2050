#include "prelab1.h"

void getArrayInfo(int *array, int size, int * distinctCount, int * largest, int * smallest) {
	int i;
	int j;
	*distinctCount = 0;
	*smallest = array[0];
	*largest = array[0];
	for (i = 0; i < size; i++) {
		for (j = i + 1; j < size; j++) {
			if (array[i] != array[j]) {
				*distinctCount += 1;
			}
		}
		if (array[i] < *smallest) {
			*smallest = array[i];
		}
		if (array[i] > *largest) {
			*largest = array[i];
		}
	}
	if (*distinctCount == 0) {
		*distinctCount = 1;
	}
}