#include "prelab5.h"

List * createObj(int obj, int * errorCode) {
	List * list = malloc(sizeof(List));
	if (list) {
		list->object = obj;
		list->next = NULL;
		*errorCode = 0;
	}
	*errorCode = 1;
	return list;
}

List * initList(int * errorCode) {
	List * list = malloc(sizeof(List));
	if (list) {
		list->next = NULL;
		return list;
		*errorCode = 0;
	}
	*errorCode = 1;
	return NULL;
}

List * insertAtHead(int insertion, List * list, int * errorCode) {
	List * newList = createObj(insertion, errorCode);
	if (errorCode == 0) {
		newList->next = list;
	}
	return newList;
}


