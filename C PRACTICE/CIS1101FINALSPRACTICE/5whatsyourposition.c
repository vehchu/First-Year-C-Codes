#include<stdio.h>
#include<stdlib.h>
#define MAX 100

//complete the function prototypes
//int* getInput(int input[]);
int* insertSorted(int arr[],int size,int num);

void main(){
   int arr[MAX], size, num;

   printf("How many numbers: ");
   //size = getInput();
   scanf("%d", &size);

   printf("Input numbers: ");
   for(int i=0; i<size; i++){
      //arr[i] = getInput();
       scanf("%d", &arr[i]);
   }
   printf("Input number to be inserted: ");
   scanf("%d", &num);
   //num = getInput();
   
   //complete the function call for insertSorted()
   insertSorted(getInput);
   
   printf("Array elements: {");
   for(int i=0; i<size; i++){
      printf("%d",arr[i]);
      if(i<size-1) printf(" ");
   }
   printf("}");
   
}

// input is an array with distinct elements and should be sorted
// insert a new number at the proper position


/*(int* getInput(int input[]){

    int* numbers = malloc(sizeof(int)*input);

    scanf("%d", numbers);
}*/

int* insertSorted(int arr[],int size,int num){

    int is_sorted, exists = 0;

// 1. check if array is sorted
    for(int i = 0; i < size; ++i){
        for(int j = 0; j < size; ++j){
            if(arr[i] < arr[j+1]){
                is_sorted = 1;
                break;
            }
            else{
                is_sorted = 0;
                break;
            }
        }
    }

//2. check if the element to be inserted exists
    for(int i = 0; i < size; ++i){
        if(num == arr[i]){
            exists = 1;
        }
    }

//      2.a. if element exists do not insert and print exists code
    if(exists == 1){
        printf("Element already exists!");
    }

// 3 if array is NOT SORTED, display fail code and DONT INSERT
    if(is_sorted == 0){
        printf("Elements are not sorted!");
    }

// 3.1. if array is sorted, INSERT number and display success code
    else if(is_sorted == 1){
        printf("Insertion successful!");
        arr[size+1] = num;
        for(int i = 0; i < size; ++i){
            for(int j = 0; j < size; ++j){
                if(arr[i] < arr[j+1]){
                    int temp = arr[i];
                    arr[i] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
    }

}