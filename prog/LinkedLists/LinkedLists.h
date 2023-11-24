#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#define MAX 10
#include <stdbool.h>

typedef struct{
    int month;
    int day;
    int year;
}date;

typedef struct{
    char name[50];
    int age;
    char gender;
    int idNum;
    date bday;
}student;

typedef struct node{
   student person[MAX];
   struct node *next;
}List, *ListPtr;

ListPtr createNode(List item);

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

#endif 