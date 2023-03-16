#include "lab6.h"

void printList(Node *list) {
	//printf("Node(%d) [ ", getSize(list));
	while(list) {
		int * data = list->data;
		printf("%p, ",data);
		list = list->next;
	}
	//puts(" ]");
}

int main() {
	int size = 5;
	//int array[] = { 1, 2, 3, 4, 5 };

	Node *list = (void *)-1;
	makeList(&list);

	/*if(list) {
		printf("ERROR: List pointer non-null after makeList() := %p\n", list);
		return 1;
	}*/


	puts("Filling and printing list");
	for(int i = 0; i < size; ++i) {
		//printList(list);
		insertAtTail(list, &i);
	}
	printList(list);
	printf("The size of the list is %d\n", getSize(list));
	printf("\nThe thing at index one is %p\n",getAtIndex(list, 1));

	puts("Removing one item from list");
	removeFromHead(list);

	/*puts("Refilling list");
	for(int i = 0; i < size; ++i) {
		insertAtTail(list, array + i);
	}*/

	puts("Freeing list");
	freeList(&list);
	if(list) {
		puts("ERROR: list non-NULL after free");
	}
}

