#include <stdio.h>
int main(){

    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Sign: ");

    if (n>0){
        printf("Positive\n");
    }
    else {
        printf("Negative\n");
    }

    printf("Parity: ");
        
    if(n%2==0){
    printf("Even\n");
    }
    else {
        printf("Odd\n");
    }
}