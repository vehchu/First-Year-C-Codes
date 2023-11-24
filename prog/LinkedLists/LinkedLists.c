#include <stdio.h>
#include <stdlib.h>
#include "LinkedLists.h"

bool insertFrontLL(List *list, List item);
bool insertRearLL(List *list, List item);
bool insertAtLL(List *list, List item, int position);
bool insertSortedLL(List *list, List item);

bool deleteFrontLL(List *list);
bool deleteRearLL(List *list);
bool deleteAtLL(List *list, int position);
bool deleteItemLL(List *list);
List deleteAllItemLL(List *list, List item);

void displayListLL(List list);

bool searchItemLL(List list, List item);
int getPositionOfItemLL(List list, List item);