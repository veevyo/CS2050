#include "lab4.h"
void printInvArray(InventoryItem * array, int length) {
	int i;
        printf("{ ");
        for (i = 0; i < length; i++) {
                printf("[%d, %.2f, %d, %d] ", array[i].ID, array[i].weight, array[i].stockCount, array[i].colors);
        }
        printf("}\n");
}

int main(void) {
	InventoryItem inv;
	inv.ID = 3221;
	inv.weight = 33.2;
	inv.stockCount = 3;
	inv.colors = 2;

	InventoryItem inv2;
	inv2.ID = 3246;
	inv2.weight = 33.2;
	inv2.stockCount = 2;
	inv2.colors = 1;

	InventoryItem * array = makeArray(2, sizeof(InventoryItem));
	array[0] = inv;
	array[1] = inv2;
	int length = getSize(array);
	printf("the length is %d\n", length);
	printInvArray(array, length);

	int counter = countWithWeight(array, 33.2);

	printf("there are %d items in the array with the same weight as tested for\n", counter);

	freeArray(array);

}
