// made by vi 

#include <stdio.h>

void convert_to_binary(int num, int octet[8], int count[8])
{
    for (int i = 0; i < 8; ++i)
    {
        if (octet[i] <= num)
        {
            if (num - octet[i] != 0)
            {
                num -= octet[i];
                count[i] = 1;
                // printf("IF: num = %d, count = %d, ind = %d\n", *num, count[i], i);
            }
            else if (num - octet[i] == 0)
            {
                num -= octet[i];
                count[i] = 1;
                // printf("ELSE IF: num = %d, count = %d, ind = %d\n", *num, count[i], i);
            }
        }
    }
}

int main()
{

    int userinp;
    int octet[8] = {128, 64, 32, 16, 8, 4, 2, 1};
    int count[8] = {0};

    printf("Enter the number you want to convert: ");
    scanf("%d", &userinp);

    printf("count: ");
    for (int i = 0; i < 8; ++i)
    {
        printf("%d ", count[i]);
    }

    convert_to_binary(userinp, octet, count);

    printf("\ncount: ");
    for (int i = 0; i < 8; ++i)
    {
        printf("%d ", count[i]);
    }

    printf("RESULTS: \n");

    printf("\nBinary of %d: ", userinp);
    for (int i = 0; i < 8; ++i)
    {
        printf("%d ", count[i]);
    }

    printf("\n\n[");
    for (int i = 0; i < 8; ++i)
    {
        printf("%d", octet[i]);
        if (i < 7)
        {
            printf("  ");
        }
    }
    printf("]");

    printf("\n");

    printf("[");
    for (int i = 0; i < 8; ++i)
    {
        printf(" %d", count[i]);
        if (i < 4)
        {
            printf("  ");
        }
        else if (i >= 4 && i < 7)
        {
            printf(" ");
        }
    }
    printf("]");

    

    return 0;
}