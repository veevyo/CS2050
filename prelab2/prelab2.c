#include "prelab2.h"

float * readFloatFileIntoArray(FILE *fptr, int *length) {
	if (fptr == NULL) {
		printf("Invalid file, try again\n");
	}
	int i;
	fscanf(fptr, "%d ", length);
	float * array = malloc(sizeof(float) * *length);
	for (i = 0; i < *length; i++) {
		fscanf(fptr, "%f ", &array[i]);
	}
	return array;
}

void freeFloatArray(float **array) {
	free(*array);
	*array = NULL;
}
