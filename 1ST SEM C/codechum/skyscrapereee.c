// COMPLETED SLAY AMAZING I LOVE U LORD SALAMAT
// 10/19/2022

#include <stdio.h>
int main(){

    int x, y, w, h, space, count;

    printf("Enter width of skyscraper: ");
    scanf("%d", &x);

    printf("Enter height of skyscraper: ");
    scanf("%d", &y);

// top of skyscraper

    if(x%2==0){
        for(space=x/2; space<x; space++){
            printf(" ");}
        printf("**");
    }
    else{
        for(space=(x/2)+1; space<=x; space++){
            printf(" ");}
        printf("*");
    }
    printf("\n");
    
// body of skyscraper

    space=1;
    if(x!=2){
        for(h=y; h>0; h--){
            for(w=x; w>0; w--){
                if(x%2==0){
                        for(; space<2;space++){
                            printf(" ");}
                    printf("*");
                }
                else{
                        for(; space<2;space++){
                            printf(" ");}
                    printf("*");
                }  
            }
            printf("\n"); 
            space=1;
        }
    }

    else{
        for(h=y-x; h>0; h--){
            for(w=x; w>0; w--){
                if(x%2==0){
                        for(; space<2; space++){
                            printf(" ");}
                    printf("*");
                }
                else{
                        for(; space<2; space--){
                            printf(" ");}
                    printf("*");
              } 
            }
            printf("\n");
            space=1; 
        }
    }

// bottom of skyscraper
  
      for(w=x+2; w>0; w--){
        printf("*");}
        
    return 0;

}