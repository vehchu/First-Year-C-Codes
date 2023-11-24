#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"

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

bool editItem(List *list, int choice, int ID){
	
	List newL;
	int pos;
	
	pos = getPositionOfItem(*list, ID);
	
	switch(choice){
		
		case 1:
		printf("\n\t\tEnter ID: ");
         scanf("%d", &newL.person[0].idNum);
         list->person[pos].idNum = newL.person[0].idNum;
         break;
      case 2: 
      	printf("\n\t\tEnter Name: ");
      	fflush(stdin);
         fflush(stdin);
         fgets(newL.person[0].name, sizeof(newL.person[0].name), stdin);
         fflush(stdin);
         fflush(stdin);
         strcpy(list->person[pos].name, newL.person[0].name);
         break;
      case 3:
		printf("\n\t\tEnter Gender: ");
		fflush(stdin);
         scanf("%c", &newL.person[0].gender);
         fflush(stdin);
         list->person[pos].gender = newL.person[0].gender;
         break;
      case 4:
		printf("\n\t\tEnter Birthday MM/DD/YYYY:");
		fflush(stdin);
        scanf("%d %d %d", &newL.person[0].bday.month, &newL.person[0].bday.day, &newL.person[0].bday.year);
        fflush(stdin);
         list->person[pos].bday.month = newL.person[0].bday.month;
         list->person[pos].bday.day = newL.person[0].bday.day;
         list->person[pos].bday.year = newL.person[0].bday.year;
         break;
       case 5:
		printf("\n\t\tEnter Age: ");
         scanf("%d", &newL.person[0].age);
         list->person[pos].age = newL.person[0].age;
         break;
		
	}
	
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
