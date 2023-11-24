#include<stdio.h>

int main(void) {
  // Hey there, start typing your C code here...
int h,i,j;
    
    printf("Enter height: ");
    scanf("%d", &h);
    printf("\n");

    if(h>2)
    {
        //upper part
        for(i=1; i<h;i+=2)
        {
            for(j=0;j<i;j++)
            {
                printf("*");
              
            }
            printf("\n");
        }

//lower part
        for(i=h; i>0;i-=2)
        {
            for(j=1;j<i;j++)
            {
                printf("*");
            }
             if(h%2!=0)
             {
                 printf("*");
             }
            printf("\n");
        }
  return 0;
}
}