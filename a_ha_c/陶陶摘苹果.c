#include <stdio.h>
#include <stdlib.h>
int main()
{
    int apples[10], height, i, total=0;
    for (i=0; i<=9; i++)
    {
        scanf("%d", &apples[i]);
    }
    
    scanf("%d", &height);
    for (i=0; i<=9; i++)
    {
        if (30+height >= apples[i])
        {
            total++;
        }
    }
    printf("%d", total);
    return 0;
}
