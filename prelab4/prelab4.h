#include <stdio.h>
#include <stdlib.h>

typedef struct { 
     int empID, jobType; 
     float salary; 
} Employee;

Employee * readEmployeeArray(FILE *fp);

int getEmpArraySize(FILE *fp);

void freeArray(void * array);

int setEmpSalary(Employee *, int empID, float salary);

int getEmpSalary(Employee *, int empID, float *salary);

int setEmpJobType(Employee *, int empID, int job);

int getEmpJobType(Employee *, int empID, int *job);

void printEmployee(Employee employee);

void printEmpArray(Employee * array, int length);

Employee readEmployee(FILE *fp);
