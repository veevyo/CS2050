#include "prelab2.h"

void printFloatArray(float * array, int length);

int main(void) {
	FILE * fp = fopen("test.txt", "rw+");
	fprintf(fp, "%d %f %f %f %f %f", 5, 3.2, 3.0, 4.5, 2.9, 9.3);
	//rewind(fp);
	int length = 0;
	float * array = readFloatFileIntoArray(fp, &length);
	printf("Length is %d\n",length);
	printFloatArray(array, length);
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

