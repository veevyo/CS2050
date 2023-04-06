#include <stdio.h>
#include <stdlib.h>

typedef struct Employee {
	int ID;
	int SSN;
}

typedef struct EmpDatabase {
	int errorCode;
	Employee * currentEmp;
}

EmpDatabase createSearchableEmployeeDB(Employee ** emp, int size);
Employee * findEmpBySSN(int SSN, EmpDatabase database);
Employee * findEmpByID(int ID, EmpDatabase database);
void freeEmpDatabase(EmpDatabase database);
int getErrorCode(EmpDatabase database);


