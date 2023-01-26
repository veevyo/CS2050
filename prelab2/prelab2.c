#include "prelab2.h"

float * readFloatFileIntoArray(FILE *fptr, int *length) {
	int filesize = 0;
	int i = 0;
	fscanf(fptr, "%d",&filesize);
	float *array = malloc(sizeof(float) * filesize);
	while (fgets(" ", sizeof(" "), fptr) != NULL) {

		fscanf(fptr, "%f ",&array[i]);
		printf("%f\n",array[i]);
		i++;
	}
	*length = (sizeof(array) / sizeof(array[0]));
	return array;
}

void freeFloatArray(float **array) {
	*array = NULL;
	free(*array);
}
