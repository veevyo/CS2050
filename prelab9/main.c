#include <stdio.h>
#include "prelab9.h"

int main(void) 
{
    // create an array of employees
    Employee* employees[5] = 
	{
        &(Employee){123456789, 100},
        &(Employee){987654321, 200},
        &(Employee){555555555, 300},
        &(Employee){111111111, 400},
        &(Employee){777777777, 500}
    };
    
    // create a searchable database from the array of employees
    EmpDatabase db = createSearchableEmployeeDB(employees, 5);
    
	printf("Employees sorted by ID:\n");
    for (int i = 0; i < 5; i++) 
	{
        printf("SSN: %d, ID: %d\n", db.byID[i]->SSN, db.byID[i]->ID);
    }

    printf("\nEmployees sorted by SSN:\n");
    for (int i = 0; i < 5; i++) 
	{
        printf("SSN: %d, ID: %d\n", db.bySSN[i]->SSN, db.bySSN[i]->ID);
    }
	
    // find employees by SSN
	printf("\nLooking for employee with SSN 123456789...\n");
    Employee* emp = findEmpBySSN(123456789, db);
    printf("Employee found by SSN: SSN=%d ID=%d\n", emp->SSN, emp->ID);
    
	printf("\nLooking for employee with SSN 555555555...\n");
    emp = findEmpBySSN(555555555, db);
    printf("Employee found by SSN: SSN=%d ID=%d\n", emp->SSN, emp->ID);
    
	printf("\nLooking for employee with SSN 999999999...\n");
    emp = findEmpBySSN(999999999, db);
    if (emp == NULL) {
        printf("Employee not found by SSN\n");
    }
    
    // find employees by ID
	printf("\nLooking for employee with ID 200...\n");
    emp = findEmpByID(200, db);
    printf("Employee found by ID: SSN=%d ID=%d\n", emp->SSN, emp->ID);
    
	printf("\nLooking for employee with ID 500...\n");
    emp = findEmpByID(500, db);
    printf("Employee found by ID: SSN=%d ID=%d\n", emp->SSN, emp->ID);
    
	printf("\nLooking for employee with ID 999...\n");
    emp = findEmpByID(999, db);
    if (emp == NULL) {
        printf("Employee not found by ID\n");
    }
    
    // free the memory allocated for the database
    freeEmpDatabase(db);
    
    return 0;
}
