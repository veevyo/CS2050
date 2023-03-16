#include "lab6.h"

void printList(Node * list) {
        printf("{");
        while (list != NULL) {
                printf("%p ", list->data);
                list = list->next;
        }
        printf("}\n");
}

int main(void) {
	int i;
	Node * head;
	makeList(&head);
        for (i=0; i<100; i++) {
                insertAtTail(head, NULL);
        }
        printList(head);
        printf("The size of the list is: %d\n", getSize(head));
	removeFromHead(head);
	printf("The new size of the list is: %d\n", getSize(head));
	printList(head);
	freeList(&head);
}
