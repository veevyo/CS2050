#include "prelab2.h"

void printFloatArray(float * array, int length);

//testing stuff
int main(void) {

	FILE * fp = fopen("test.txt", "r+");
	fprintf(fp, "%d %f %f %f", 3, 2.2, 1.33, 44.2);
	rewind(fp);
	int length = 0;
	float * array = readFloatFileIntoArray(fp, &length);
	printf("Length is %d\n",length);
	printFloatArray(array, length);
	freeFloatArray(&array);
	if (array == NULL) {
		printf("Array free successful!\n");
	}
}

void printFloatArray(float * array, int length) {
	int i;
	printf("{");
	for (i = 0; i < length; i++) {
		if (i == length - 1) {
			printf("%f}\n", array[i]);
		}
		else {
			printf("%f, ", array[i]);
		}
	}
}

