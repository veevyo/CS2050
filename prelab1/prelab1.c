#include "prelab1.h"

void getArrayInfo(int *array, int size, int * distinctCount, int * largest, int * smallest) {
	int i;
	int j;
	*distinctCount = 0;
	*smallest = array[0];
	*largest = array[0];

	//most of the action happens in this for loop
	for (i = 0; i < size; i++) {
		//check against other values and see if there are duplicates in the arr
		for (j = 0; j < i; j++) {
			if (array[i] == array[j]) {
				break;
			}
		}
		if (i == j) {
			*distinctCount += 1;
		}
		//kinda self explanatory code
		if (array[i] < *smallest) {
			*smallest = array[i];
		}
		if (array[i] > *largest) {
			*largest = array[i];
		}

	//the counter should be 1 if there's only one value in the whole thing just repeated
	}
	if (*distinctCount == 0) {
		*distinctCount = 1;
	}
}
