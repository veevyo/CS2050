#include "prelab3.h"

void printArray(int * array, int size);

int main(void) {
	int size = 3;
	int type = sizeof(int);
	void * array = createArray(size, type);
	printf("Array has been initialized as: ");
	printArray((int *)array, size);
	int testsize = getArraySize(array);
	printf("The size of the array is %d elements\n", testsize);
	freeArray(&array);
	if (array == NULL) {
		printf("Array freed successfully!\n");
	}
}

void printArray(int * array, int size) {
         int i;
         printf("{");
         for (i = 1; i < size + 1; i++) {
                if (i == size) {
                         printf("%d}\n", array[i]);
                 }
                 else {
 			printf("%d, ", array[i]);                 
		}
	}
}
