/*
Create a program that asks for a user's weight in kg and height in cm, and then computes for and categorizes the BMI. See the table below:
Underweight: Below 18.5
Normal     : From 18.5 to below 25.0
Overweight : From 25.0 to below 30.0
Obese      : 30.0 and upwards

Display both the BMI (2 decimal places) and its category.

Example 1:
Enter your weight in kg: 70
Enter your height in cm: 156
Your BMI: 28.76
Category: Overweight

Example 2:
Enter your weight in kg: 52
Enter your height in cm: 169
Your BMI: 18.21
Category: Underweight

#include <stdio.h>
int main(){

    float kg, cm, bmi;

    printf("Enter your weight in kg: ");
    scanf("%f", &kg);

    printf("Enter your height in cm: \n");
    scanf("%f", &cm);

    bmi = kg/((cm/100)*(cm/100));
    
    
    printf("Your BMI: %.2f\n", bmi);
    
    if(bmi<18.5){
    printf("Category: Underweight");}

    if(bmi>=18.5 && bmi<25){
    printf("Category: Normal");}

    if(bmi>=25 && bmi<30){
    printf("Category: Overweight");}

    if(bmi>30){
    printf("Category: Obese");}

    return 0;

} */
 
#include <stdio.h>

int main(void)
{
    typedef double kg;
    typedef double cm;

    kg weight = 0.0;
    cm height = 0.0;
    
    double bmi;

    printf("Enter your weight in kg: ");
    scanf("%lf", &weight);

    printf("Enter your height in cm: ");
    scanf("%lf", &height);

    height /= 100;  // convert cm to m
    bmi = weight / (height * height); // BMI = w/h^2

    printf("Your BMI: %.2f\nCategory: ", bmi);
    if (bmi < 18.5)
        printf("Underweight");
    else if (bmi < 25.0)
        printf("Normal");
    else if (bmi < 30.0)
        printf("Overweight");
    else
        printf("Obese");

    return 0;
}
