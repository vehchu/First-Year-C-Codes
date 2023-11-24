#include<stdio.h>
#define price 7.50
#define UNLICALL 25

//complete the function prototype
float updateBalance(float bal, int num);

void main(){
   float bal;
   int num;
   float answer, updatebal, neededbal;

   printf("Input balance: ");
   scanf("%f",&bal);
   printf("Input number of persons to call: ");
   scanf("%d",&num);

   //complete the function call
   answer = updateBalance(bal, num);
   neededbal = answer*price;
   
   //print the final lines of the display here

    if(neededbal >= UNLICALL && bal >= UNLICALL){
       updatebal = bal-UNLICALL;
    }
    else{
        updatebal = bal - neededbal;
    }

    printf("\nUpdate balance: P%.2f\n", updatebal);
    printf("Persons called: %.0f\n", answer);

    if(answer != num){
        printf("Insufficient balance to call everyone");
    }
}

float updateBalance(float bal, int num){
    //write your code here

    float updatebal = bal, neededbal = num*price;
    int personcalled = num;

    //calls per person = P 7.50
    // 0. figure out how much i'm gonna spend for that number of persons
    // 1. check if the number of persons called is enough for the balance
    // 2. if i have enough, just call the people; spend that money
    // 3. if i don't have enough, spend the amount that you can spend
    // end, return the number of people you were able to call

    //printf("%.2f", neededbal);

    if(bal >= neededbal){ // have enough money
        if(neededbal > UNLICALL){
            updatebal -= UNLICALL;
        }
        else{
            updatebal = updatebal - neededbal;
        }
    }

    else if(neededbal > bal){ // dont have enough money but,,,
        if(bal >= UNLICALL){ // have enough money for unlicall
            updatebal -= UNLICALL;
        }
        else{                   //only have enough 
            personcalled = 0;
            while(updatebal > price){
                updatebal = updatebal - price;
                personcalled++;                   
            }
        }
    }

    return personcalled; 
}
