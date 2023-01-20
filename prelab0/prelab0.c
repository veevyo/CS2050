#include "prelab0.h"

int greaterThanOrEqualToCounter(int numbers[], int size, int query) {
	int i;
	int counter = 0;
	for (i = 0; i < size; i++) {
		if (numbers[i] >= query) {
			counter++;
		}
	}
	return counter;
}