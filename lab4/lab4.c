#include "lab4.h"

/* this function accepts an int for the amount of elements in the array and an int for the size of each element in the array. it creates an array that could be of any type theoretically and returns it to the user */
void * makeArray (int arraySize , int elementSize ) {
	int * array = malloc((arraySize * elementSize) + elementSize); //we initialize it as an int so we can store the size at the beginning
	if (!array) {
		return NULL;
	}
	array[0] = arraySize;
	array++; //pointer arithmetic so the size is stored at array[-1]
	return array;
}

/* this function accepts an array of any type, ideally (and we assume) an array created with makeArray(). it looks for that aforementioned value at array[-1] and returns it to the user */
int getSize ( void * array ) {
	int * intarray = (int *) array;
	return intarray[-1];
}

/* this function is a building block for countWithWeight. it accepts an InventoryItem object and a weight float and compares a single item's weight to the user's given weight. it returns 1 on same weight, 0 on different*/
int sameWeight(InventoryItem item, float weight) {
	if (item.weight == weight) {
		return 1;
	}
	return 0;
}
/* this function counts the amount of items that have the same weight as a user's given weight. it accepts an InventoryItem array and uses sameWeight inside of a for loop to compare every item's weight inside the array to the user's given weight */
int countWithWeight ( InventoryItem * items , float weight ) {
	int i;
	int length = getSize(items);
	int counter = 0;
	for (i = 0; i < length; i++) {
		if (sameWeight(items[i], weight)) {
			counter++;
		}
	}
	return counter;
}
/* this function accepts an array of any type and frees it from memory */
void freeArray(void * array) {
	array = array - 4;
	free(array);
	array = NULL;
}
