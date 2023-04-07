#include "lab9.h"

/*accepts two integers, one representing the length of the array and one representing the size of each element, and allocates memory for the array storing the size of the array at the -1th element. O(1) time*/
void * makeArray(int arraySize, int elementSize) {
	int * array = malloc((arraySize * elementSize)+elementSize);
	if (array) {
		array[0] = arraySize;
		array++;
		return array;
	}
	return NULL;
}

/*accepts an array and returns its size in the form of the -1th element. it is assumed the array being passed was created with the provided makeArray() function by the user. O(1) time*/
int getSize(void * array) {
	int * intArr = (int *)array;
	return intArr[-1];
}

/*helper function. accepts a Client array, a start index, an end index, and a Client pointer query, and returns the index of the given query. this function assumes the given array is already in sorted order. O(log(n)) time*/
int binarySearch(Client * array, int start, int end, Client * query) {
	int mid = start + (end - start)/2;
	if (end >= start) {
        	if (array[mid].accountWorth == query->accountWorth) {
                	return mid;
        	}   
		if (array[mid].accountWorth > query->accountWorth) {
			return binarySearch(array, start, mid - 1, query);
		}
		return binarySearch(array, mid+1, end, query);
	}
	return -1;
}

/*accepts a Client array and a Client pointer query. after using the size to get the init start and end indices, it uses the binarySearch() helper fucntion. O(log(n)) time*/
int searchClients(Client * array, Client * query) {
	int size = getSize(array);
	int start = 0;
	int end = size - 1;
	return binarySearch(array, start, end, query);
}

/*accepts two Client pointers (a and b). returns -1 if b is greater, returns 1 if a is greater, returns 0 otherwise (e.g. if they are equal). O(1) time*/
int compareClients(Client * a, Client * b) {
	if (a->accountWorth < b->accountWorth) {
		return -1;
	}
	if (a->accountWorth > b->accountWorth) {
		return 1;
	}
	return 0;
}

/*accepts an array and frees it. it is assumed that the passed array was created by the user using the given makeArray() function. O(1) time*/
void freeArray(void * array) {
	array = array - sizeof(int);
	free(array);
	array = NULL;
}
