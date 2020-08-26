#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i = 1;
    int j;
    while (i<=5)
    {
        j = 1;
        while (j<=i)
        {
            printf("%d", i);
            j++;
        }
        printf("\n");
        i++;
    }
    return 0;
}
