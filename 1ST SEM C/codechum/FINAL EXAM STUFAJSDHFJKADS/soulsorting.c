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
    display(sorting_souls);
    
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
int n;
    printf("[");
    for(int i = 0; i < sizeof(arr) - 1; i++) {
        arr[i] = arr[i+1];

            for(int i = 1; i <= arr[0]; ++i) {
                printf("%d", arr[i]);

                 if(i < arr[0]) {
                    printf("|");
                    }
            }

            n = sizeof(arr) - 1; 
    }
    printf("], SOUL COUNT: %d\n", n);

/*    printf("[");
    for(int i = n - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
        printf("%d", arr[i]);
            if(i < arr[0]) {
                printf("|");
            }
    }

    printf("], SOUL COUNT: %d\n", sizeof(arr));
*/
}