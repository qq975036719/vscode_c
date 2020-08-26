#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a[3][4], x;
    x = 0;
    
    for (int i=0; i<=2; i++)
        for (int j=0; j<=3; j++)
        {   
            a[i][j] = x;
            x++;
        }
    
    for (int i=0; i<=2; i++)
    {
        for (int j=0; j<=3; j++)
            printf("%d\t", a[i][j]);
    
        printf("\n");
    }    
    return 0;
}