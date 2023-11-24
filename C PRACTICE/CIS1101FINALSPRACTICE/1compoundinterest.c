#include<stdio.h>

//complete the function prototype
float computeCompoundInterest(float p, int rate, int years);

void main(){
   float p;
   int rate, years;
   float answer;

   printf("Input principal: ");
   scanf("%f", &p);
   printf("Input rate (percent): ");
   scanf("%d", &rate);
   printf("Input number of years: ");
   scanf("%d", &years);

   //complete the function call
   answer = computeCompoundInterest(p, rate, years);
   
   //print the final line of the display here

   printf("Total interest in %d years: P%.2f", years, answer);

}

float computeCompoundInterest(float p, int rate, int years){
   //write your code here

    float percent = rate/100.0f;
    float inter, a;

    a = (1+percent);
    
    // a = 10000*(1+0.05/1)

    //inter = pow(a, years);

      inter = a*p;

    for (int i = 0; i < years-1; i++){
         inter *= a;  
    }

    //printf("%f\n", inter); 

    return inter - p; 
}