/*
Description     : IDK HOW TO USE POINTER POINTERS WITH DYNAMIC MEMORY ALLOCAIOTN
Author          : G.M. Yongco #BeSomeoneWhoCanStandByShinomiya
Date            : ur my date uwu
*/
//HEAD ------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//CustomFuncitons -------------------
char** Seprate();
int ConvertStringToInt();
char ClassOf();
int NetworkAddress(int arrIP[], int arrNA[], int arrBA[], char class);
void Display(int Network[], int Broadcast[], int Usable, char class);

//MAIN -----------------------------------------------------------------
int main()
{
    int i;
    char IPStr[99];
    int IPInt[5];
    char IPClass;
    int IPNA[4];
    int IPBA[4];

    printf("octet1.octet2.octet3.octet4/prefix\nExample: 77.187.73.88/28\nEnter the IP: ");
    scanf("%s", IPStr);

    char** Positions = Seprate(IPStr);

    for(i = 0; i<5; ++i){
        IPInt [i] = ConvertStringToInt(Positions[i]);
    }

    IPClass = ClassOf(IPInt[4]);

    int UsableIPpow = NetworkAddress(IPInt, IPNA, IPBA, IPClass);

    Display(IPNA, IPBA, UsableIPpow, IPClass);

    /*
    for testing to see the individual inputs
    for(i = 0; i<5; ++i){
        printf("%d : %s\n", (Positions[i]), (Positions[i]));
    }
    for(i = 0; i<5; ++i){
        printf("%d\n", IPInt[i]);
    }
    */
}

//CustomFuncitons -------------------
char** Seprate(char input[]){
    int i;

    char** Position = malloc(sizeof(char*)*5);

    char SC;        //Short for separator Character
    Position[0] = input;
    for(i = 1; i <= 4; ++i){

        (i < 4)?(SC = '.'):(SC = '/');

        Position[i] = strchr(Position[i-1], SC) + 1;    //finds the position after SC
        *(Position[i] - 1) = '\0';
    }
    return Position;
}
int ConvertStringToInt(char* string){
    int i;
    int TheInt = 0;

    for(i = 0; string[i] != '\0'; ++i){
        TheInt *= 10;
        TheInt += string[i] - 48; // a little bit of ASCII magic
    }

    return TheInt;
}
char ClassOf(int x){

    char class;

    if(x < 8){
        printf("Error: WTf is that prefix");
        class = 'E';    //E for error
    }else if(x >= 8 && x < 16){
        class = 'A';
    }else if(x >= 16 && x < 24){
        class = 'B';
    }else if(x >= 24 && x < 30){
        class = 'C';
    }else{
        printf("Something went Wrong in the ClassSystem");
    }

    return class;
}
int NetworkAddress(int arrIP[], int arrNA[], int arrBA[], char class){
    int i;
    int count1;
    int bit8 = 255;

    switch (class){
        case 'A':
            count1 = 1;
            break;
        case 'B':
            count1 = 2;
            break;
        case 'C':
            count1 = 3;
            break;
        default:
            count1 = 1;
            printf("Something went Wrong in the switchcase");
            break;
    }

    for(i = 0; i<count1; i++){
        arrNA[i] = arrIP[i];
        arrBA[i] = arrIP[i];
    }
    for(i = count1 + 1; i<4; ++i){
        arrNA[i] = 0;
        arrBA[i] = 255;
    }

    // we calcluate broadcast address first because its convenient
    
    int BAbinary = pow(2, (8-(arrIP[4] % 8))) - 1;
    int NAbinary = 255 - BAbinary;

    arrNA[count1] = arrIP[count1] & NAbinary;
    arrBA[count1] = arrIP[count1] | BAbinary;

    //Usable Host Address -----------
    int UHAPow = (32-arrIP[4]);
    
    return UHAPow;
}
void Display(int Network[], int Broadcast[], int Usable, char class){
    int i;

    printf("The network is class\t: %c \n", class);
    printf("Network Address\t\t: ");
    for(i = 0; i<4; ++i){
        printf("%d", Network[i]);
        (i < 3)? (printf(".")):(printf("\n"));
    }
    printf("Broadcast Address\t: ");
    for(i = 0; i<4; ++i){
        printf("%d", Broadcast[i]);
        (i < 3)? (printf(".")):(printf("\n"));
    }
    printf("Number of usable IP\t: %d\n", (int)pow(2, Usable));
    printf("Or expressed as\t\t: 2^(%d) - 2", Usable);
}