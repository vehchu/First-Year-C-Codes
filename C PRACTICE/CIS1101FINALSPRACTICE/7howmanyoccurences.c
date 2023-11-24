#include<stdio.h>
#include<stdlib.h>
#define MAX 10

//complete the function prototypes
int *createCountArray(int arr[], int size);

void main(){
   int arr[MAX] = {0};
   int *answer, size;

   printf("How many numbers? ");
   scanf("%d", &size);

   printf("Input numbers: ");
   
   for(int i=0; i<size; i++){
      scanf("%d", &arr[i]);
   }
   
   //complete the function call
   answer = createCountArray(arr, size);

   //complete the code below to display the result as indicated
   printf("\n");
    for(int i = 0; i < 10; i++) 
      printf("Count of %d: %d\n", i, *(answer + i)/* or answer[i] */);
   
   
   // *(pArr + i) = arr[i]
   // pArr + i = &arr[i]
}

int *createCountArray(int arr[], int size){

   // create a new array
   // each index in the array corresponds to the number of occurrences of the index #/value
   // count the number of times a value comes up
   // assign that to the corresponding index of the arr
int element;
   int *count = malloc(sizeof(int) * MAX);

   for(int i = 0; i < MAX; i++) count[i] = 0;                 //initialize each element to 0
   
   /*for(int i = 0; i < 10; i++){ // for loop that goes through count[]
      for(int j = 0; j < size; j++){ // loop that goes through arr[]
         if(i == arr[j])
            count[i]++;
      } 
   }*/

   for(int i = 0; i < MAX; ++i){
      element = arr[i];
      count[element]++;
   }
   
   return count;
}
