 //1. Pointer Calculator
 // do all arithmetic operations using pointers


 #include <stdio.h>
 int main(){

    float x, y, sum, difference, dividen, product;
    float* num1 = &x;
    float* num2 = &y;

    printf("Enter the first number: ");
    scanf("%f", &x);

    printf("\nEnter the second number: ");
    scanf("%f", &y);

    sum = *num1 + *num2;
    difference = *num1 - *num2;
    dividen = *num1 / *num2;
    product = *(num1) * *(num2);

    printf("Sum = %f\n", sum);
    printf("Difference = %f\n", difference);
    printf("Dividen = %f\n", dividen);
    printf("Product = %f\n", product);

    return 0; 

 }