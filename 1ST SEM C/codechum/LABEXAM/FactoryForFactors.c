#include <stdio.h>
#include<stdlib.h>

// FUNC DECL // 
int *get_factors(int list[], int count, int value);
void display(int list[], int count);

int main(){

// VARIABLES //

int num, value, i;
int number[30];

// FUNCTIONS //

printf("How many numbers? ");
scanf("%d", &num);

for(i = 0; i < num; i++){
    printf("Enter the number %d: ", i+1);
    scanf("%d", &number[i]);
}

printf("Enter the value: ");
scanf("%d", &value);

printf("The collection: ");
display(number, num);

printf("The factors of %d present in the collection: ", value);
get_factors(number, num, value);


return 0;
}

// CUSTOM FUNCTIONS//

int *get_factors(int list[], int count, int value){

    printf("{");
    for(int i = 0; i < count; i++){
        if(list[i] % value == 0){
            printf("%d", list[i]);
             if( i < count - 1){
                printf(", ");
            }
        }
    }
     printf("}\n");

}

void display(int list[], int count){
    
     printf("{");
     for(int i = 0; i < count; i++){
        printf("%d", list[i]);
        if( i < count - 1){
                printf(", ");
            }
     }
     printf("}\n");
}

