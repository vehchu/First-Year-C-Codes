#ifndef ARRAYLIST_H
#define ARRAYLIST_H
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

typedef struct{
   student person[MAX];
   int count;
}List;

List createList();
void initList (List *list);

bool insertFront(List *list, List item);
bool insertRear(List *list, List item);
bool insertAt(List *list, List item, int position);

bool deleteFront(List *list);
bool deleteRear(List *list);
bool deleteAt(List *list, int position);
bool deleteItem(List *list, int ID);

void displayList(List list);

bool searchItem(List list, int ID);
int getPositionOfItem(List list, int ID);

List* getFemale(List *list);
List* getMale(List *list);

bool editItem(List *list, int choice, int ID);

List* sortListAge(List *list);
List* sortListID(List *list);
List* sortName(List *list);

#endif