#include <stdlib.h>
#include <stdio.h>
#include "prelab9.h"


void mergeByID(Employee** arrayOfPointers, Employee** tempArray, int low, int mid, int high) 
{
    int i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high) 
	{
        if (arrayOfPointers[i]->ID < arrayOfPointers[j]->ID)
		{
            tempArray[k++] = arrayOfPointers[i++];
        } 
		
		else 
		{
            tempArray[k++] = arrayOfPointers[j++];
        }
    }
    while (i <= mid) 
	{
        tempArray[k++] = arrayOfPointers[i++];
    }
	
    while (j <= high) 
	{
        tempArray[k++] = arrayOfPointers[j++];
    }
	
    for (int i = low; i <= high; i++) 
	{
        arrayOfPointers[i] = tempArray[i];
    }
}

void mergeSortByID(Employee** arrayOfPointers, Employee** tempArray, int low, int high) 
{
    if (high <= low) 
	{
        return;
    }
	
    int mid = low + (high - low) / 2;
	
    mergeSortByID(arrayOfPointers, tempArray, low, mid);
    mergeSortByID(arrayOfPointers, tempArray, mid + 1, high);
    mergeByID(arrayOfPointers, tempArray, low, mid, high);
}

void mergeBySSN(Employee** arrayOfPointers, Employee** tempArray, int low, int mid, int high) 
{
    int i = low, j = mid + 1, k = low;
	
    while (i <= mid && j <= high) 
	{
        if (arrayOfPointers[i]->SSN < arrayOfPointers[j]->SSN) 
		{
            tempArray[k++] = arrayOfPointers[i++];
        } 
		
		else 
		{
            tempArray[k++] = arrayOfPointers[j++];
        }
    }
	
    while (i <= mid) 
	{
        tempArray[k++] = arrayOfPointers[i++];
    }
	
    while (j <= high) 
	{
        tempArray[k++] = arrayOfPointers[j++];
    }
	
    for (int i = low; i <= high; i++) 
	{
        arrayOfPointers[i] = tempArray[i];
    }
}

void mergeSortBySSN(Employee** arrayOfPointers, Employee** tempArray, int low, int high) 
{
    if (high <= low) 
	{
        return;
    }
	
    int mid = low + (high - low) / 2;
	
    mergeSortBySSN(arrayOfPointers, tempArray, low, mid);
    mergeSortBySSN(arrayOfPointers, tempArray, mid + 1, high);
    mergeBySSN(arrayOfPointers, tempArray, low, mid, high);
}




// create a searchable employee database from an array of employee pointers
EmpDatabase createSearchableEmployeeDB(Employee **employees, int n) 
{
	EmpDatabase db = {NULL, NULL, n, 0}; //Initializes database pointer
	
    db.bySSN = malloc(sizeof(Employee *) * n); //Allocates memory to bySSN pointer
    db.byID = malloc(sizeof(Employee *) * n); //Allocates memory to byID pointer
	
    if (!db.bySSN || !db.byID) //Checks for malloc failure for both mallocs 
    {
        db.error = 1; //Assigns error code
        return db;
    }
	
    for (int i = 0; i < n; i++)
    {
        db.bySSN[i] = employees[i]; //Coppies info into new database for SSN sorting
        db.byID[i] = employees[i]; //Copies info into new database for ID sorting
    }
    mergeSortBySSN(db.bySSN, malloc(sizeof(Employee *) * n), 0, n - 1); //Calls mergeSortBySSN to sort by SSN
    mergeSortByID(db.byID, malloc(sizeof(Employee *) * n), 0, n - 1); //Calls mergeSortByID to sort by ID 
    return db;
}



Employee *findEmpBySSN(int SSN, EmpDatabase db) {
    int lo = 0, hi = db.n - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (db.bySSN[mid]->SSN == SSN) {
            return db.bySSN[mid];
        } else if (db.bySSN[mid]->SSN < SSN) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return NULL; // employee not found
}



// find an employee by ID using binary search
Employee *findEmpByID(int ID, EmpDatabase db) 
{
    int lo = 0, hi = db.n - 1;
    while (lo <= hi) 
	{
        int mid = (lo + hi) / 2;
        if (db.byID[mid]->ID == ID) 
		{
            return db.byID[mid];
        } 
		else if (db.byID[mid]->ID < ID) 
		{
            lo = mid + 1;
        } else 
		{
            hi = mid - 1;
        }
    }
    return NULL; // employee not found
}



// free the memory allocated for an employee database
void freeEmpDatabase(EmpDatabase db) 
{
    free(db.bySSN);
    free(db.byID);
}



// get the error code for an employee database
int getErrorCode(EmpDatabase db) 
{
    return db.error;
}
