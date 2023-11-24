
#include <stdio.h>

int main() {

    int height, bruh, huh;

    printf("Enter height: ");
    scanf("%d", &height);

    printf("\n");

 if(height>2){
    if(height %2 == 0){
        for(huh = 1; huh<=height; huh+=2){
            for(bruh = 1; bruh <= huh; bruh++){
            printf("*");
        }
        printf("\n");
    }
    
        for(huh = height-1; huh>=1; huh-=2){
            for(bruh = 1; bruh <= huh; bruh++){
            printf("*");}
        printf("\n");
        }
    }
    
    else{
        for(huh = 1; huh<=height; huh+=2){
            for(bruh = 1; bruh <= huh; bruh++){
            printf("*");
        }
        printf("\n");
    }
    
    for(huh = height-2; huh>=1; huh-=2){
        for(bruh = 1; bruh <= huh; bruh++){
            printf("*");}
        printf("\n");
        }
    }
 }
    else{
        printf("Invalid");
    }
 return 0;
}


/*#include<stdio.h>

int main() {

    int height, bruh, huh;

    printf("Enter height: ");
    scanf("%d", &height);

    printf("\n");

 if(height>2){
        for(huh = 1; huh<height; huh+=2){
            for(bruh = 0; bruh <huh; bruh++){
            printf("*");
        }
        printf("\n");
    }
    
        for(huh = height-1; huh >= 1; huh-=2){
            for(bruh = 1; bruh <= huh; bruh++){
            printf("*");}
        printf("\n");
        }
    }
 
 return 0;
} */