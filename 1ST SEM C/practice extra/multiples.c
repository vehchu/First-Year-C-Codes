#include <stdio.h>
int main(){

    int a, b, c, rem;

    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    rem = b % c;
    b -= rem;

    while(b >= a){
        printf("%d ", b);
        b -= c;
        }

    return 0;
}

/* #include <stdio.h>

int main()
{
    int x,y,z;
    scanf("%d%d%d",&x,&y,&z);
    
    while (y>x){
        if (x%z==0){
            printf("%d ",x);
        }
        x++;
    }
    return 0;
}
*/