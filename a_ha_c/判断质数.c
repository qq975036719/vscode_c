#include <stdio.h>
#include <stdlib.h>
int main()
{
    int number;
    scanf("%d", &number);
    
    int issushu;
    int a = number-1;
    for (a; a>1; a--)
    {
        if (number%a==0) issushu = 0;
    }
    if (issushu) printf("%d是素数！", number);
    else printf("%d不是素数！", number);
    return 0;
}
