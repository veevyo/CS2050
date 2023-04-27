#include "prelab11.h"

EmpDatabase createSearchableEmployeeDB() {
	EmpDatabase * empDB = malloc(sizeof(EmpDatabase));
	if (!empDB) {
		empDB->error = 1;
		return NULL;
	}
	return *empDB;
}


EmpDatabase insertEmp(Employee * emp, EmpDatabase empDB) {
	empDB.size++;
}

int getErrorCode(EmpDatabase empDB) {
	return empDB.error;
}

