#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i = 1;
    int j;
    int temp = 1;
    while (i<=5)
    {
        j = 1;
        while (j<=i)
        {
            printf("%d\t", temp);
            j++;
            temp++;
        }
        printf("\n");
        i++;
    }
    return 0;
}
