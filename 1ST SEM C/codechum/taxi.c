/*
In Cebu, the fare for trips taken via taxi depends on the distance traveled and the time taken to 
complete the journey.The minimum fare is 40 pesos which then increases by 2 pesos for every full 
minute and 13 pesos and 50 centavos for every full kilometer traveled.
Create a user-friendly program to simulate the situation by computing the taxi fare based on 
the distance in kilometers and estimated journey time provided by the user in minutes. Inputs shall not be restricted to just integers.

*/

#include <stdio.h>
int main(){

    float dist, time, fare, minFare=40;

    printf("Enter how many kilometers you travelled: ");
    scanf("%f", &dist);

    printf("Enter how long (in minutes) you travelled: ");
    scanf("%f", &time);
    
    fare = minFare+(2*time)+(13.50*dist);

    printf("Your taxi fare is P%.2f", fare);

    return 0;
}