#include "lab9.h"

int main(void) {
	Client * client1 = malloc(sizeof(Client));
	Client * client2 = malloc(sizeof(Client));
	Client * client3 = malloc(sizeof(Client));
	client1->accountWorth = 300;
	client2->accountWorth = 400;
	client3->accountWorth = 500;
	Client * array = makeArray(3, sizeof(Client));
	printf("array size is %d\n",getSize(array));
	array[0] = *client1;
	array[1] = *client2;
	array[2] = *client3;
	printf("client1 is located at index %d\n", searchClients(array, client1));
	printf("client2 is located at index %d\n", searchClients(array, client2));
	printf("client3 is located at index %d\n", searchClients(array, client3));
	int litmusTest = compareClients(client3, client1);
	if (litmusTest > 0){
		printf("client3 is more than client1\n");
	}
	else if (litmusTest < 0) {
		printf("client3 is less than client1\n");
	}
	else {
		printf("client3 is the same as client1\n");
	}
	freeArray(array);
	printf("%f\n",array[0].accountWorth);

}
