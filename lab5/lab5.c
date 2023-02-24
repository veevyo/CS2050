#include "lab5.h"

/*helper function for creating node objects*/
Node * createObj(void * obj) {
        Node * list = malloc(sizeof(Node));
        list->data = obj;
        list->next = NULL;
        return list;
}

/*accepts a list double pointer and inits the list*/
int makeList(Node ** list) {
        *list = malloc(sizeof(Node));
        return 0;
}

/*accepts a list pointer and gets list size*/
int getSize(Node * list) {
	int counter;
	while (list != NULL) {
		counter++;
		list = list->next;
	}
	return counter;
}

/*accepts a list double pointer and void data pointer and uses this to insert node at tail of list*/
int insertAtTail(Node ** list, void * data) {
        Node * newList = createObj(data);
	if (!newList) {
		return 1;
	}	
        newList->next = *list;
	*list = newList;
	return 0;
}

/*accepts a list double pointer and removes node from head of list*/
void * removeFromHead(Node ** list) {
	Node * temp = (*list);
	(*list) = (*list)->next;
	free(temp);
	return list;
}

/*accepts a list double pointer and frees list*/
void freeList(Node ** list) {
	Node * temp = *list;
	while ((*list) != NULL) {
		temp = *list;
		*list = (*list)->next;
		free(temp);
	}
}

