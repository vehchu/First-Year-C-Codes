// created by vi hehe :>

int dectobin(int *userinp, int *octet, int (*count)[8], int rows, int size);
int display(int *userinp, int *octet, int (*count)[8], int rows, int size);

#include <stdio.h>
#define MAX 100
int main()
{

    int userinp[MAX], size;
    int octet[8] = {128, 64, 32, 16, 8, 4, 2, 1};
    int count[8][8];
    int rows = 8;

    printf("How many numbers do you want to convert? ");
    scanf("%d", &size);

    if (size == 1)
    {
        printf("Enter the number you want to convert: ");
        scanf("%d", &userinp[0]);

        dectobin(userinp, octet, count, rows, size);
        display(userinp, octet, count, rows, size);
    }
    else
    {
        printf("Enter the numbers you want to convert: ");

        for (int i = 0; i < size; ++i)
        {
            scanf("%d", &userinp[i]);
        }

        for (int i = 0; i < size; ++i)
        {
            dectobin(userinp, octet, count, rows, size);
        }
        display(userinp, octet, count, rows, size);
    }

    printf("user : %d", *userinp);

    return 0;
}

int dectobin(int *userinp, int *octet, int (*count)[8], int rows, int size)
{
    // TO DO:
    // 1. make it so that it takes in multiple numbers
    // 2. return all of those numbers

    int **num = &userinp;

    for (int j = 0; j < size; ++j)
    {
        for (int i = 0; i < 8; ++i)
        {
            for (int x = 0; x < 8; ++x)
            {
                if (*(octet + i) > **num)
                {
                     count[i][x] = 0;
                    // printf("octet = %d count = %d, num = %d\n", octet[i], count[i], *num);
                }
                else
                {
                    if (**num - *(octet + i) != 0)
                    {
                        **num -= *(octet + i);
                        count[i][x]  = 1;
                        // printf("IF: num = %d, count = %d, ind = %d\n", *num, count[i], i);
                    }
                    else if (**num - *(octet + i) == 0)
                    {
                        **num -= *(octet + i);
                         count[i][x] = 1;
                        // printf("ELSE IF: num = %d, count = %d, ind = %d\n", *num, count[i], i);
                    }
                }
            }
        }
    }
}

int display(int *userinp, int *octet, int (*count)[8], int rows, int size)
{
    // print all of the numbers

    for (int j = 0; j < size; ++j)
    {
        printf("\nRESULTS:\n");

        printf("Binary of %d: ", *userinp);
        for (int i = 0; i < 8; ++i)
        {
            for (int j = 0; j < 8; ++j)
            {
                printf("%d ", *(*count+i)+j);
            }
        }

        printf("\n[");
        for (int i = 0; i < 8; ++i)
        {
            printf("%d", octet[i]);
            if (i < 7)
            {
                printf("  ");
            }
        }
        printf("]");

        printf("\n[");
        for (int i = 0; i < 8; ++i)
        {
            for (int j = 0; j < 8; ++j)
            {
                printf(" %d", *(*count+i)+j);
                if (i < 4)
                {
                    printf("  ");
                }
                else if (i >= 4 && i < 7)
                {
                    printf(" ");
                }
            }
        }
        printf("]\n\n");
    }
}
