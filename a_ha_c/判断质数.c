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
    if (issushu) printf("%d��������", number);
    else printf("%d����������", number);
    return 0;
}
