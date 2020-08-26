#include <stdio.h>
#include <stdlib.h>
int main()
{
    for (int x=100; x<=999; x++)
    {
        int a = x/100;
        int b = x/10%10;
        int c = x%10;
        if (x == a*a*a + b*b*b + c*c*c)
            printf("%d\t", x);
    }
    return 0;
}
