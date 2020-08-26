#include <stdio.h>
#include <stdlib.h>
int main()
{
    char a[101], t;
    int i, j, len;
    
    gets(a);
    len = strlen(a);
    
    for (i=0; i<=len-2; i++)
    {
        for (j=i+1; j<=len-1; j++)
            {
                if (a[i]>a[j])
                {
                    t = a[i];
                    a[i] = a[j];
                    a[j] = t;
                }
            }
    }
    puts(a);
    return 0;
}
