#include <stdio.h>
int main(){

    long int a, b, i; 

    printf("Enter start of range: ");
    scanf("%li", &a);

    printf("Enter end of range: ");
    scanf("%li", &b);


    if(a%2==0)
    {
        printf("Even numbers in range: ");
        for(i=a; i<=b;i+=2){
            printf("%li ", i);
        }

        printf("\nOdd numbers in range: ");
        for(i=a+1; i<=b; i+=2){
        printf("%li ", i);
        }
    }

    if(a%2!=0)
    {
        printf("Odd numbers in range: ");
        for(i=a; i<=b; i+=2){
        printf("%li ", i);
        }

        printf("\nEven numbers in range: ");
        for(i=a+1; i<=b; i+=2){
        printf("%li ", i);
        }
    }

    return 0;

}