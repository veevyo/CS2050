#include "prelab5.h"

/*accepts an object and error code; returns a list with the new object back to the user. error code is 1 on fail and 0 on success*/
List * createObj(int obj, int * errorCode) {
	List * list = malloc(sizeof(List));
	if (!list) {
		*errorCode = 1; 
		return NULL;
  	}
	list->object = obj;
	*errorCode = 0;
	list->next = NULL;
	return list;
}

/*inits list. errorcode is 1 on fail and 0 on success*/
List * initList(int * errorCode) {
	List * list = createObj(0, errorCode);
	if (!list) {
		*errorCode = 1;
		return NULL;
	}
	list->next = NULL;
	*errorCode = 0;
	return list;
}

/*takes an insertion and inserts at head of list. accepts an insertion, list and error code. error code is 1 on fail and 0 on success*/
List * insertAtHead(int insertion, List * list, int * errorCode) {
	List * newList = createObj(insertion, errorCode);
	if (!list) {
		*errorCode = 1;
		return NULL;
	}
	newList->next = list;
	*errorCode = 0;
	return newList;
}

/*takes an index and list and iteratively goes thru the list and returns value at index*/
int getAtIndex(int index, List * list) {
	int counter = 0;
	while (list != NULL) {
		++counter;
		if (counter == index) {
			return list->object;
		}
		list = list->next;
	}
	return 0;
}

/*takes a list and iteratively goes thru and counts amt of things in list*/
int getListLength(List * list) {
	int counter = 0;
	while (list != NULL) {
		++counter;
		list = list->next;
	}
	return counter;
}

/*takes a list and frees it*/
List * freeList(List * list) {
	List * temp = list;
	while (list != NULL) {
		temp = list;
		list = list->next;
		free(temp);
	}
	return list;
}
