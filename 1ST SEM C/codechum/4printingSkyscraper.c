#include<stdio.h>
int main(){
    int w, h, i, n;

    printf("Enter width of skyscraper: ");
    scanf("%d", &w);

    printf("Enter height of skyscraper: ");
    scanf("%d", &h);

    i=1;
    while(i<=h && w!=0){
        n=1;
        if(i==h){
            if(h!=1){
                printf("\n");
            }
            do{
                printf("*");
                n++;
            }while(n<=w+2 && w!=1);
        }
        if(i!=1 && i<h){
            printf("\n");
            printf(" ");
            do{
                printf("*");
                n++;
            }while(n<=w);
            printf(" ");
        }
        if(i==1 && h!=1){
            do{
                if(w%2==0 && n==((w+2)/2)){
                    printf("*");
                    printf("*");
                }
                if((w%2)!=0 && n==((w+2)-((w+2)/2))){
                    printf("*");
                }
                if(w==1){
                    printf(" ");
                    printf("*");
                } else{
                    printf(" ");
                }
                n++;
            }while(n<=w);
            printf(" ");
        }
        i++;
    }
    return 0;
}
