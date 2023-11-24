#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "wayne.h"

#define MAX 10

int main(void) {

    int array[MAX] = {1, 2, 3, 4, 5, 6, 7};
    int count = 7; 
    
    //initialize the array
    //initialize(array, &count);

    //variables for command selection, number input, and position selection
    int command;
    int elem, pos;
    
    //return value
    int ret;
    
    //for the array of even numbers (command #12)
    int *even;
    
    do {
      system("cls");
      printf("\n-------------------");
      printf("\n 1  - Initialize/reset array");
      printf("\n 2  - Display array");
      printf("\n 3  - Search for an element");
      printf("\n 4  - Insert new element at the end");
      printf("\n 5  - Insert new element at the start");
      printf("\n 6  - Insert new element at a custom position");
      printf("\n 7  - Delete an element at the end");
      printf("\n 8  - Delete an element at the start");
      printf("\n 9  - Delete an element at a custom position");
      printf("\n 10 - Delete a specific element");
      printf("\n");
      printf("\n 11 - Get the range");
      printf("\n 12 - Get the even numbers");
      printf("\n 13 - Check if sorted in ascending order");
      printf("\n 14 - Moving the smallest element to the beginning of the array");
      printf("\n 15 - Sort array");
      printf("\n");
      printf("\n 0  - Exit");
      printf("\n-------------------");
      printf("\nCOMMAND #: ");
      scanf("%d", &command);
      
      switch(command) {
        case 1:
          initialize(array, &count);
          printf("\nArray initialized!");
          break;
        case 2:
          display(array, count);
          printf("\n");
          break;
        case 3:
          printf("Enter element: ");
          scanf("%d", &elem);
          ret = searchElem(array, count, elem);
          if(ret!=-1){
        	printf("\nElement found at index %d.",ret);
		  }else{
		  	printf("\nElement not found.");
		  }
          printf("\n");
          break;
        case 4:
          printf("Enter element: ");
          scanf("%d", &elem);
          ret = insertLast(array, &count, elem);
          if(ret!=0){
        	printf("\nElement successfully inserted!");
		  }else{
		  	printf("\nOperation failed.");
		  }
          break;
        case 5:
          printf("Enter element: ");
          scanf("%d", &elem);
          ret = insertFirst(array, &count, elem);
          if(ret!=0){
        	printf("\nElement successfully inserted!");
		  }else{
		  	printf("\nOperation failed.");
		  }
		  break;
 		case 6:
          printf("Enter element: ");
          scanf("%d", &elem);
          printf("Enter position: ");
          scanf("%d", &pos);
          ret = insertAtPos(array, &count, elem, pos);
          if(ret!=0){
        	printf("\nElement successfully inserted!");
		  }else{
		  	printf("\nOperation failed.");
		  }
		  break;
        case 7:
          ret = removeLast(array, &count);
          if(ret!=0){
        	printf("\nElement successfully removed!");
		  }else{
		  	printf("\nOperation failed.");
		  }
          break;
        case 8:
          ret = removeFirst(array, &count);
          if(ret!=0){
        	printf("\nElement successfully removed!");
		  }else{
		  	printf("\nOperation failed.");
		  }
          break;
        case 9:
          printf("Enter position: ");
          scanf("%d", &pos);
          ret = removeAtPos(array, &count, pos);
          if(ret!=0){
        	printf("\nElement successfully removed!");
		  }else{
		  	printf("\nOperation failed.");
		  }
          break;
        case 10:
          printf("Enter element: ");
          scanf("%d", &elem);
          ret = removeElem(array, &count, elem);
          if(ret!=0){
        	printf("\nElement successfully removed!");
		  }else{
		  	printf("\nOperation failed.");
		  }
          break;
        case 11:
          printf("\nThe range is %d", getRange(array, count));
          break;
        case 12:
          even = getEven(array, count);
          printf("\nEven numbers: ");
          for(pos=0; even[pos]!=-1; pos++){
          	printf("%d ",even[pos]);
		  }
		  break;
		case 13:
		  ret = isSortedAscending(array, count);
          if(ret==1){
        	printf("\nElements are sorted.");
		  }else{
		  	printf("\nElements are not sorted.");
		  }
		  break;
		case 14:
		  moveSmallestToFirst(array, count);
          printf("\nSmallest element transferred to beginning of array.");
          break;
        case 15:
		  sortArray(array, count);
          printf("\nArray is sorted!");
          break;
      }
      if(command!=0){
      	printf("\nPress any key to continue.");
        getch();	
	  }
    } while (command != 0);

    return 0;
}
