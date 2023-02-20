typedef struct listStruct { 
      int object; 
      struct listStruct *next; 
} List;

List * initList(int * errorCode);
List * insertAtHead(int insertion, List * list, int * errorCode);
int getAtIndex(int index, List * list);
int getListLength(List * list);
List * freeList(List * list);
