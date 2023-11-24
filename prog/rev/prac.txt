#include <stdio.h>

void disp(int arr[]);
void makeOdd(int arr[]);

//input num looped 5, 1 vi
int main() {

int arr[5];
int x;

    printf("Enter 5 numbers:\n");

    for(x=0; x < 5; x++){
        scanf("%d",&arr[x]);
    }

    disp(arr);
    makeOdd(arr);
    printf("\n");
    disp(arr);
}

void disp(int arr[]) {

    int x; 

    for(x=0; x < 5; x++){   
        printf("%d ", arr[x]);
    }

}

void makeOdd(int arr[]){

//make the even inputs to odd
    int y;

    for(y=0;y < 5; y++) {
        if (arr[y] % 2 == 0) {
            arr[y] = arr[y] + 1;
        }
    }

    printf("\n");

}