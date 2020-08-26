#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a[10], i, num;
    
    for (i=0; i<=9; i++)
        a[i] = 0;
    
    for (i=1; i<=5; i++)
    {   
        scanf("%d", &num);
        a[num] = 1; 
    }
    
    for (i=0; i<=9; i++)
        if (a[i] == 0)
            printf("%d ", i);
    return 0;
}
