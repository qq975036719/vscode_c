#include <stdio.h>
#include <stdlib.h>
int main()
{
    for (int i=1; i<=9; i++)
    {
        for (int j=1; j<=i; j++)
        {
            if (i!=j)
            {
                printf("%d*%d=%d\t", j, i, j*i);
            }
            else
            {
                printf("%d*%d=%d\n", j, i, j*i);
            }
            
        }
    }
    return 0;
}
