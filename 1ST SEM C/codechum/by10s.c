#include <stdio.h>
int main(){
    int n=0, i=0, l;

    do
    {   
        n=0;
        printf("Enter size: "); 
        scanf("%d", &n);
        
        if(n>50)
        {
            printf("Number must be below 50!\n");
        }

        else
        {
            do
            {
                printf("%d ", i);
                i++;

                    if(l<9){
                        l++;
                    }
                        else{
                            printf("\n");
                            l=0;
                        }
            }
                while(i<n);
        }
    }
        while(n>50);
    
return 0;

}