#include <stdio.h>

#include <stdlib.h>

int main()
{
    int n, sum=0;
    scanf("%d",&n);
    
    for (n; n>=1; n/=10)
    {
        sum += n%10;
    }
    printf("%d", sum);

return 0;
}