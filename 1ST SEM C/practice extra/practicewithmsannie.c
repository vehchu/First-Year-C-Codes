/*

#include <stdio.h>
int main(){

    float s, a;

    printf("Enter side of square: ");
    scanf("%f", &s);

    a = s*s ;

    printf("The area of the square is %f", a);

    return 0;
    
}

#include <stdio.h>
int main(){

int a, b, c;  

    printf("Enter the number whose multiples you need: ");
    scanf("%d", &c); 

    printf("Enter starting number of range: ");
    scanf("%d", &a);

    printf("Enter ending number of range: ");
    scanf("%d", &b);
    
        while(a<=b)
            {
	        if(a%c==0)
	            {   	
		        printf ("%d ", a);
	        }
	        a++;
            }   
 return 0;        
}


#include <stdio.h>

int main(){

    float l, w, a, p; 

    printf("Enter the length of your rectangle: ");
    scanf("%f", &l);

    printf("\nEnter the width of your rectangle: ");
    scanf("%f", &w);

    // area wl, p 2l+w

    a = l*w;
    p = 2*(l+w);

    printf("\nThe area of the rectangle is %.2f, while the perimeter of the rectangle is %.2f\n", a, p);

    return 0;
}



#include <stdio.h>
int main(){

    long int n;

    printf("Enter a number you want to identify as ODD or EVEN: ");
    scanf("%li", &n);

    if(n%2==0){
        printf("This number is an EVEN number");
    }
    else{
        printf("This number is an ODD number");
    }

    return 0;
}

*/

#include <stdio.h>
int main(){

    long int a, b, n; 

    printf("Enter start of range: ");
    scanf("%li", &a);

    printf("Enter end of range: ");
    scanf("%li", &b);

    for(n=a; a%2==0 && a<=b; a+=2){
        printf("%li ", a);
    }

    for(n=a+1; a%2!=0 && a<=b; a+=1){
        printf("%li ", a);

    }
    return 0; 
}