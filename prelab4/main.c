#include "prelab4.h"

int main(void) {
	FILE * fp = fopen("test.txt", "r");
	//rewind(fp);
	//int length = getEmpArraySize(fp);
	//rewind(fp);
	Employee * array = readEmployeeArray(fp);
	printf("employee [1] id = %d\n", array[1].empID);
	printEmpArray(array, 3);
	printf("we are going to change employee 2231's salary to $30,000.33\n");
	setEmpSalary(array, 2231, 30000.33);
	printEmpArray(array, 3);
}	
