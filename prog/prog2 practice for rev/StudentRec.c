#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef enum {TRUE, FALSE}bool;

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

//answer these:
bool insertFront(List *list, List item);
bool insertRear(List *list, List item);
bool insertAt(List *list, List item, int position);

bool deleteFront(List *list);
bool deleteRear(List *list);
bool deleteAt(List *list, int position);
bool deleteItem(List *list, int ID);

bool searchItem(List list, int ID);
int getPositionOfItem(List list, int ID);

List* getFemale(List *list);
List* getMale(List *list);

List* sortListAge(List *list);
List* sortListID(List *list);
List* sortName(List *list);

void displayList(List list);

List createList(){
    
    List list;
    
    list.count = 0; 
    
    return list;
}

void initList (List *list){

    list->count = 0;
    
}

bool insertFront(List *list, List item){
    
   
}

bool insertRear(List *list, List item){

   
}

bool insertAt(List *list, List item, int position){
    
   
}

bool deleteFront(List *list){
    
  

}

bool deleteRear(List *list){

  
}

bool deleteAt(List *list, int position){

}

bool deleteItem(List *list, int ID){

    
}

void displayList(List list){
    
    printf("\n\t-------- CURRENT LIST --------");
    for(int i = 0; i < list.count; ++i){
        printf("\n\t[Student %d]", list.person[i].idNum);
        printf("\n\t Name: %s", list.person[i].name);
        printf("\t Age: %d", list.person[i].age);
        printf("\n\t Gender: %c", list.person[i].gender);
        printf("\n\t Birthday: %d/%d/%d \n", list.person[i].bday.month, list.person[i].bday.day, list.person[i].bday.year);
    }
}

bool searchItem(List list, int ID){

    
    
}

int getPositionOfItem(List list, int ID){

     
}

List* getFemale(List *list){


}

List* getMale(List *list){

  
}



List* sortListAge(List *list){

}

List* sortListID(List *list){

   
}

List* sortName(List *list){

   
}
