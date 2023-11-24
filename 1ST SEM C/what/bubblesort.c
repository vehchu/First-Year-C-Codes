#include <stdio.h>
                                                           
void bubbleSort(int array[], int size){                  // perform the bubble sort
    for (int step = 0; step < size - 1; ++step){         // loop to access each array element
        for (int i = 0; i < size - step - 1; ++i){       // loop to compare array elements
            if (array[i] > array[i + 1]){                // compare two adjacent elements
                int temp = array[i];                     // change > to < to sort in descending order
                array[i] = array[i + 1];                 // swapping occurs if elements
                array[i + 1] = temp;                     // are not in the intended order
            }
        }
    }
}

void printArray(int array[], int size){                  // print array
    for (int i = 0; i < size; ++i) {
         printf("%d  ", array[i]);
    }
    printf("\n");
}

int main(){

    int data[10];

    for(int i = 0; i < 10; i++){
        printf("Number %d: ", i+1);
        scanf("%d", &data[i]);
    }

    int size = sizeof(data) / sizeof(data[0]);          // find the array's length

    bubbleSort(data, size);
  
    printf("Sorted Array in Ascending Order:\n");
    printArray(data, size);

}