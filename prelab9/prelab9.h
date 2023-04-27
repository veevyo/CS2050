#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int SSN;
    int ID;
} Employee;

typedef struct {
    Employee** bySSN;
    Employee** byID;
    int n;
    int error;
} EmpDatabase;

EmpDatabase createSearchableEmployeeDB(Employee**, int);
Employee* findEmpBySSN(int, EmpDatabase);
Employee* findEmpByID(int, EmpDatabase);
void freeEmpDatabase(EmpDatabase);
int getErrorCode(EmpDatabase);

void mergeByID(Employee**, Employee**, int, int, int);
void mergeSortByID(Employee**, Employee**, int, int);
void mergeBySSN(Employee**, Employee**, int, int, int);
void mergeSortBySSN(Employee**, Employee**, int, int);