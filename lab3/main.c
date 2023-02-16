#include "lab3.h"

void printCharArray(int size, char * array) {
	int i;
	printf("{");
	for (i = 0; i < size; i++) {
		if (i == size - 1) {
			printf("%c}\n", array[i]);
		}
		else {
			printf("%c, ", array[i]);
		}
	}
}

int main(void) {
	char * array = strAlloc(6);
	char * array2 = strAlloc(6);
	int size = strLen(array);
	int size2 = strLen(array2);
	printf("The allocated string1 is: ");
	printCharArray(size, array);
	printf("The size of this string1 is %d\n", size);
	printf("The allocated string2 is ");
	printCharArray(size2, array2);
	printf("The size of this string2 is %d\n", size2);
	array[0] = 'H';
	array[1] = 'O';
	array[2] = 'A';
	array[3] = 'R';
	array[4] = 'D';
	array[5] = 'S';
	printf("I've changed string1. It is now: ");
	printCharArray(size, array);
	strCpy(array, array2);
	printf("I've changed string2 using strCpy. It is now: ");
	printCharArray(size2, array2);
	array[0] = 'S';
	array[1] = 'D';
	array[2] = 'R';
	array[3] = 'A';
	array[4] = 'O';
	array[5] = 'H';
	int sameness = strCmpRev(array, array2);
	if (sameness == 1) {
		printf("string1 is the same as string2\n");
	}
	else {
		printf("string1 is different from string2 reversed\n");
	}
	//strFree(array);
}
