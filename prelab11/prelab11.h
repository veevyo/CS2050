#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int SSN;
	int ID;
	struct Employee *next, *back;
} Employee;

typedef struct {
	Employee head;
	int size;
	int error;
} EmpDatabase;

EmpDatabase createSearchableEmployeeDB();
EmpDatabase insertEmp(Employee * emp, EmpDatabase empDB);
int countEmpsInSalaryRange(int min, int max, EmpDatabase empDB);
void freeEmpDatabase(EmpDatabase empDB);
int getErrorCode(EmpDatabase empDB);
