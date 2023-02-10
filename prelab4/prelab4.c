#include "prelab4.h"

int getEmpArraySize(FILE *fp) {
	if (fp == NULL) {
		return -1;
	}
	int length = 0;
	fscanf(fp, "%d ", &length);
	return length;
}
Employee * readEmployeeArray(FILE *fp) {
	if (fp == NULL) {
		printf("fail");
	}
	int i;
	int length = getEmpArraySize(fp);
	printf("length is %d\n", length);
	Employee * array = malloc(sizeof(Employee) * length);
	printf("if malloc fails, i won't print!\n");
	for (i = 0; i < length; i++) {
		array[i] = readEmployee(fp);
		//printf("%d, %d, %.2f\n", array[i].empID, array[i].jobType, array[i].salary);
	}
	return array;

}

Employee readEmployee(FILE *fp) {
	Employee employee;
	if (fp == NULL) {
		printf("fail");
	}
	fscanf(fp, "%d  %d  %f", (&employee.empID), (&employee.jobType), (&employee.salary));
	return employee;
}

/*void printEmployee(Employee employee) {
	printf("[");
	printf("%d, ", employee.empID);
	printf("%d, ", employee.jobType);
	printf("%f, ", employee.salary);
	printf("]");
}*/

void printEmpArray(Employee * array, int length) {
	int i;
	printf("{");
	for (i = 0; i < length; i++) {
		printf("[%d, %d, %.2f] ", array[i].empID, array[i].jobType, array[i].salary);
	}
	printf("}\n");
}
