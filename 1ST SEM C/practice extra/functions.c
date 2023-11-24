#include <stdio.h>

void addition(int n1, int n2){
    int sum = n1 + n2;
    printf("The sum of those numbers are %d", sum);

}

int main(){

    int num1, num2;

    printf("Enter two numbers: ");
    scanf("%d %d/n", &num1, &num2);

    addition(num1, num2);

}