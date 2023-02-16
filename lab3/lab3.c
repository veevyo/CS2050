#include "lab3.h"

char * strRev(char * str);

/*accepts an integer for size, allocates memory for a string. it also sets the 0th element to hold the size, and then sets the pointer an index off, so there's a size hidden at arr[-1]*/
char * strAlloc(int size) {
	char * str = malloc(size * sizeof(char));
	str[0] = size;
	str++;
	return str;
}
/*returns aforementioned hidden size*/
int strLen(char *str) {
	return (int) str[-1];
}
/*accepts two arrays and copies the contents of the first array into the second. assumes arr 2 is at least as big as arr1*/
void strCpy(char *source , char *dest) {
	int size = strLen(source);
	int i;
	for (i = 0; i < size; i++) {
		dest[i] = source[i];
	}
}
/*accepts char arr and reverses it in place*/
char * strRev(char * str) {
	int size = strLen(str);
	int i;
	char temp;
	for (i = 0; i < size; i++) {
		temp = str[i];
		str[i] = str[size - i - 1];
		str[size + i - 1] = temp;
	}
	return str;
}
/*compares two strings; if equal, return 1, else 0*/
int strCmp(char * str1, char * str2) {
	int size = strLen(str1);
	int i;
	for (i = 0; i < size; i++) {
		if (str1[i] != str2[i]) {
			return 0;
		}
	}
	return 1;
}
/*combines last two functions into one; reverses the dest string and compares it to the unaltered source*/
int strCmpRev(char *source , char *dest) {
	strRev(dest);
	return strCmp(source, dest);
}
/*frees str*/
void strFree(char *str) {
	str = str - sizeof(int); //must offset pointer since we hid the size in arr[-1]
	free(str);
	str = NULL;
}
