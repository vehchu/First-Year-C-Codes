#include <stdio.h>

int main(){

// VARIABLES //

int x, y;
int i, j, c;
int size[30];
int elem[30];

// FUNCTIONS //

printf("Enter the size of the array: ");
scanf("%d", &size[30]);

for(i = 0 ; i < size[30]; i++){
    printf("Element #%d: ", i+1);
    scanf("%d", &elem[i]);    
}

printf("Enter x and y: ");
scanf("%d %d", &x, &y);

for(i = 0; i < size[30]; i++){
    printf("Element #%d = ", i+1);

    if(elem[i] >= x && elem[i] <= y){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
    
}

return 0;
}