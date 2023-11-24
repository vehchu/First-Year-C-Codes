#include <stdio.h>
#define MAX 26

int main(){

    char ary[MAX];
    ary[0];

    printf("Enter something: ");
    scanf("%c", &ary[0]);

    for(int i=0; i<MAX; i++){
        ary[i] = ary [0] + i;
    }

    printf("Array element[0]: %c", ary[0]);
    printf("\nArray element[%d]: %c", MAX-1, ary[MAX-1]);
    printf("\nArray : %s", ary);

    return 0;

}