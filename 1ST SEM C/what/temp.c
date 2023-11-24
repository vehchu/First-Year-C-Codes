#include <stdio.h>

int* Bubble_Sort(int[]);
int main(){

    int arr[10];
    int *p, i, a;

    p = arr;

    for(i = 0; i < 10; i++){
        printf("Number #%d: ", i+1);
        scanf("%d ", *(p+i));  
    }

    printf("\n");

//printing of bubblesort

    p = Bubble_Sort(arr);

    printf("Sorted elements in ascending order:\n");

    for(i = 0; i < 10; i++){
        printf("%d ", *(p+i));
    }

// bubble sort function
    int* Bubble_Sort(int arr[]){
        int i, j, temp, a[30]; 
            for(i = 0; i < 10; i++){
                printf("%d:%d\n", i, a[i]);
                for(j = i+1; j < 10; j++){
                    if(arr[j] < a[i]){
                        temp = a[i];
                        arr[i] = a[j];
                        a[j] = temp;
                    }
                    printf("%d:%d\t", j, a[j]);
                }
            }
            printf("\n");
    }
    return a;
}