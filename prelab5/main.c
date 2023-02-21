#include "prelab5.h"
void printList(List * n) {
	while (n != NULL) {
		printf(" %d ", n->object);
		n = n->next;
	}
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
}
