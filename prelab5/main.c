#include "prelab5.h"
void printList(List * list) {
	printf("{");
	while (list != NULL) {
		printf("%d ", list->object);
		list = list->next;
	}
	printf("}\n");
}
int main(void) {
	int i;
	List * head;
	int errorCode;
	head = initList(&errorCode);
	for (i=0; i<100; i++) {  
    		head=insertAtHead(i, head, &errorCode);
	}
	printList(head);
	printf("The 3rd list value is: %d\n", getAtIndex(3, head));
	printf("The size of the list is: %d\n", getListLength(head));
	freeList(head);
	printList(head); //after being freed, this should segfault
}
