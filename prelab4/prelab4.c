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
	Employee * array = malloc(sizeof(int) + (sizeof(Employee) * length));
	printf("if malloc fails, i won't print!\n");
	array[0].empID = length;
	array++;
	printf("size is %d\n", array[-1].empID);
	for (i = 0; i < length; i++) {
		array[i] = readEmployee(fp);
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

void printEmpArray(Employee * array, int length) {
	int i;
	printf("{ ");
	for (i = 0; i < length; i++) {
		printf("[%d, %d, %.2f] ", array[i].empID, array[i].jobType, array[i].salary);
	}
	printf("}\n");
}

int scanForEmpID(Employee * employee, int empID, int * pos) {
	int length = employee[-1].empID;
	int i;
	for (i = 0; i < length; i++) {
		if (employee[i].empID == empID) {
			*pos = i;
			return 0;
		}
	}
	return 1;
}

int setEmpSalary(Employee * employee, int empID, float salary) {
	int pos = 0;
	int check = scanForEmpID(employee, empID, &pos);
	printf("printing pos so it works %d\n", pos);
	if (check == 0) {
		employee->salary = salary;
		return 0;
	}
	return 1;
}

int getEmpSalary(Employee * employee, int empID, float *salary) {
	int pos = 0;
	int check = scanForEmpID(employee, empID, &pos);
	if (check == 0) {
		*salary = employee[pos].salary;
		return 0;
	}
	return 1;
}
