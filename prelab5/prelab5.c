#include "prelab5.h"


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
