#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 10

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

List* sortListAge(List *list);
List* sortListID(List *list);
List* sortName(List *list);

List createList(){
    
    List list;
    
    list.count = 0; 
    
    return list;
}

void initList (List *list){

    list->count = 0;
    
}

bool insertFront(List *list, List item){
    
    int i = 0;
    if(list->count < MAX){
        for(i = list->count; i > 0; --i){ //shifts everything to the right
            list->person[i] = list->person[i-1];
        }
        list->person[0] = item.person[0]; //adds item in the front of the array
        (list->count)++;    //update count
        
        return true; 
    }
    
    return false;
}

bool insertRear(List *list, List item){

    if(list->count < MAX){
        list->person[(list->count)++] = item.person[0];
        return true;
    }

    return false;
}

bool insertAt(List *list, List item, int position){
    
    list->count++;
    
    for(int i = 0; i <= position; ++i){
        if(i == position){

            for(int j = list->count; j > position; --j){ //shifts everything to the right
                list->person[j] = list->person[j-1];
            }

            list->person[i] = item.person[0];
            return true;
        }    
    }
    
    return false;
}

bool deleteFront(List *list){
    
    for(int i = 0; i != list->count; ++i){
        list->person[i] = list->person[i+1];
    }
    
    list->count--;

}

bool deleteRear(List *list){

    (list->count)--;

}

bool deleteAt(List *list, int position){

    for(int i = 0; i <= position; ++i){
        if(i == position){
            for(int j = position; j != list->count; ++j){
                    list->person[j] = list->person[j+1];
                }
        }    
    }
    list->count--;
}

bool deleteItem(List *list, int ID){

    for(int i = 0; i < list->count; ++i){
        if(list->person[i].idNum == ID){
            for(int j = i; j < list->count; ++j){
                    list->person[j] = list->person[j+1];
                }
            list->count--;
            return true;
        } 
    }
    return false;
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

    for(int i = 0; i < list.count; ++i){
        if(list.person[i].idNum == ID){
                printf("\nStudent %d exists in the system\n", ID);
            return true;
        }
        else{
            printf("\nStudent %d does not exist in the system\n", ID);
            return false;
        }
    }
    
}

int getPositionOfItem(List list, int ID){

      for(int i = 0; i < list.count; ++i){
        if(list.person[i].idNum == ID){
            return i; 
        }    
    }
}

List* getFemale(List *list){

    List * FemList = (List*)malloc(sizeof(List));

    initList(FemList);

    for(int i = 0; i < list->count; ++i){
        if(list->person[i].gender == 'F' || list->person[i].gender == 'f'){
            FemList->person[FemList->count++] = list->person[i];
        }    
    }

    return FemList;

}
List* getMale(List *list){

    List * MaList = (List*)malloc(sizeof(List));

    initList(MaList);

    for(int i = 0; i < list->count; ++i){
        if(list->person[i].gender == 'M' || list->person[i].gender == 'M'){
            MaList->person[MaList->count++] = list->person[i];
        }    
    }

    return MaList;

}


List* sortListAge(List *list){

    List * newList = list;
    List temp;

    for(int i = 0; i < newList->count; ++i){
        for(int j = i+1; j < newList->count; ++j){
            if(newList->person[i].age < newList->person[j].age){
                temp.person[0] = newList->person[i];
                newList->person[i] = newList->person[j];
                newList->person[j] = temp.person[0];
            }
        }
    }

    return newList;
}

List* sortListID(List *list){

    List * newList = list;
    List temp;

    for(int i = 0; i < newList->count; ++i){
        int min = newList->person[i].idNum, min_idx = i;
        for(int j = i+1; j < newList->count; ++j){
            if(newList->person[i].idNum < min){
                min_idx = j;
                min = newList->person[j].idNum;
            }  
        }
        temp.person[0] = newList->person[i];
        newList->person[i] = newList->person[min_idx];
        newList->person[min_idx] = temp.person[0];
    }

    return newList;

}

List* sortName(List *list){

    List * newList = list;
    List temp;

    for(int i = 0; i < newList->count; ++i){
        for(int j = 0; j < newList->count-1; ++j){
            if((strcmp(newList->person[i].name, newList->person[j+1].name))>0){
                temp.person[0] = newList->person[i];
                newList->person[i] = newList->person[j+1];
                newList->person[j+1] = temp.person[0];
            }
        }
    }

    return newList;
}
