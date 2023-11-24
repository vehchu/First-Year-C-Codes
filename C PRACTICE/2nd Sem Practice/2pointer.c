// 2. swap using call by reference
// reference - using the address

int swap(int* x, int* y);

#include <stdio.h>
int main(){

    int x, y;

    printf("INT MAIN\n");
    printf("Enter your first number: ");
    scanf("%d", &x);
    printf("Enter your second number: ");
    scanf("%d", &y);

    swap(&x, &y);

    printf("\nINT MAIN: SWAPPED\n");
    printf("Your numbers swapped: %d %d", x, y);
    
    return 0;
}

int swap(int* x, int* y){

    int temp; 

    temp = *x;
    *x = *y;
    *y = temp;

    printf("INT SWAP\n");

    printf("Int X: %d", *x);
    printf("\nInt Y: %d", *y);

}