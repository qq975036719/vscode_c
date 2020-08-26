#include <stdio.h>
#include <string.h>

int main()
{
    int a[120], i, n, x;
    while(scanf("%d",&n)!=EOF)
    {
     memset(a, 0, sizeof(a));
     for(i = 0;i<n;i++)
     {
      scanf("%d",&x);
      a[x]++;
     }
     int maxi = 0;
     for(i = 1;i<120;i++)
     {
      if(a[i]>maxi)
      {
       maxi = a[i];
      }
     }
     printf("%d\n",maxi);
    }
    return 0;
}