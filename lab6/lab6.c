#include "lab6.h"

/*accepts a double pointer to a list and uses it to create a list. this implementation uses a dummy node. returns 0 on success, 1 on failure*/
int makeList(Node ** list) {
	*list = malloc(sizeof(Node));
	(*list)->next = NULL;
	if (*list){
		return 0;
	}
	return 1;
}

/*helper function to create an object in a list*/
Node * createObj(void * obj) {
	Node * list = malloc(sizeof(Node));
	list->data = obj;
	list->next = NULL;
	return list;
}

/*function which accepts a list pointer and uses it to get the size of the list. returns size of list*/
int getSize(Node * list) {
	int counter = 0;
	list = list->next; //offset by one to account for dummy node
	while (list) {
		counter++;
		list = list->next;
	}
	return counter;
}

/*function which accepts a list pointer and an index and uses this information to find the data at the given point. returns NULL on failure*/
void * getAtIndex(Node * list, int index) {
	int size = getSize(list);
	int point = 0;
	list = list->next; //offset by one to account for dummy node
	if (index < 0 || index > size) {
		return NULL;
	}
	while(list) {
		if (point == index) {
			return list->data;
		}
		list = list->next;
		point++;
	}
	return NULL;
}

/*function which accepts a list pointer and a void pointer to data and uses this to insert a new object at the tail of the list*/
int insertAtTail(Node * list, void * data) {
        Node * newList = createObj(data);
        if (!newList) {
                return 1;
        }
        newList->next = list->next;
        list->next = newList;
        return 0;
}

/*function which accepts a list pointer and uses this to remove an element from the head of the list*/
void * removeFromHead(Node * list) {
	list = list->next;
	Node * temp = list;
	list = list->next;
	free(temp);
	return list;
}

/*function which accepts a double pointer to a list and uses this to free all elements inside the list*/
void freeList(Node ** list) {
	Node * temp = *list;
	while ((*list) != NULL) {
		temp = *list;
		*list = (*list)->next;
		free(temp);
	}
	*list = NULL;
	
}
