#include <stdio.h>
#include <stdlib.h>
int main()
{
    for (int i=1; i<=7; i+=2)
    {
        int num = (9-i)/2;
        for (int j=1; j<=num; j++)
        {
            printf(" ");
        }
        for (int temp=1; temp<=i; temp++)
        {
            printf("*");
        }
        printf("\n");
    }
    
    
    printf("*********\n");
    
    
    for (int i=7; i>=1; i-=2)
    {
        int num = (9-i)/2;
        for (int j=1; j<=num; j++)
        {
            printf(" ");
        }
        for (int temp=1; temp<=i; temp++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}

