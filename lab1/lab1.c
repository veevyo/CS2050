#include "lab1.h"

/*function takes array, size, and float variable result. it calculates what the average of all values in the array is, if an only if:
1) there are at least 2 values to add together and get the avg of
2) the array isn't just full of zeros (you can't divide by 0 to get the avg so this would break it)*/

int getAverage(int array[], int size , float *result) {
	int i;
	*result = 0;
	if (size < 2) {
		return 1;
	}
	float sum;
	for (i = 0; i < size; i++) {
		sum += array[i];
	}
	if (sum == 0) {
		return 1;
	}
	*result = sum / size;
	return 0;
}

/*function takes array, size, and int variable result. it calculates what the sum of all even numbes in the array is, if and only if:
1) there are at least 2 values to add together
2) there are even values to add together in the first place*/

int sumEven(int array[], int size , int *result) {
	int i;
	*result = 0;
	int evenCounter = 0;
	if (size < 2) {
		return 1;
	}
	for (i = 0; i < size; i++) {
		if (array[i] % 2 == 0) {
			*result += array[i];
			evenCounter++;
		}
	}
	if (evenCounter == 0) {
		return 1;
	}
	return 0;
}
