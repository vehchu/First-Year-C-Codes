#include <stdio.h>
#include <string.h>

int main(){

    char name[50] = "Alice";
    char last[50] = "Wonder";
    
    printf("%s %s\n", name, last);

    strcpy(name, "Candice");

    printf("%s %s\n", name, last);


    strcat(name, " C. "); //value of name is now Candice C. 

    printf("%s %s\n", name, last);

    printf("%s", name);


    return 0;
    
    }