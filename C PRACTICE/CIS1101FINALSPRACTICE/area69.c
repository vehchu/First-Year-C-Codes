#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 50
#define INT_MIN -2147483648
#define INT_MAX 214748364

void display(int arr[]);
int *sorting_souls(int arr[]);

int main() {
    int list[MAX_SIZE];

    printf("Enter number of souls: ");
    scanf("%d", &list[0]);

    printf("Enter soul scores: ");
    for(int i = 1; i <= list[0]; ++i) {
        scanf("%d", &list[i]);
    }

    printf("Initial soul list: ");
    display(list);

    
    printf("Sorted soul list: ");
    // Hey there, start typing your C code here...
    int *soul = sorting_souls(list);
    display(sorting_souls(list));
    
    return 0;
}

void display(int arr[]) {
    printf("[");
    for(int i = 1; i <= arr[0]; ++i) {
        printf("%d", arr[i]);
        if(i < arr[0]) {
            printf("|");
        }
    }
    printf("], SOUL COUNT: %d\n", arr[0]);
}

int *sorting_souls(int arr[]) {
    // Hey there, start typing your C code here...

    // 1. look for the first occurrence of the second highest

    int highest = INT_MIN;
    int i;

    for(i = 1; i <= arr[0]; i++){
        if(arr[i] > highest){
            highest = arr[i];
        }
    }

    int second = INT_MIN;
    int index_ofsecond;

    for(i = 1; i <= arr[0]; i++){
        if(arr[i] > second && arr[i] != highest){
            second = arr[i];
            index_ofsecond =  i;
        }
    }

    // 2. create a new array that contains everything after the first occurrence

    int *new_arr = malloc(sizeof(int) * MAX_SIZE);

    for(i = index_ofsecond; i <= arr[0]; i++){
        new_arr[i - index_ofsecond + 1] = arr[i];
    }

    *new_arr = arr[0] - index_ofsecond + 1;

    // 3. return the new array

    return new_arr;
}