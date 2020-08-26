#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char a[5][11], temp[11];
    int i, j;
    
    for (i=0; i<=4; i++)
        gets(a[i]);
    
    for (i=0; i<=3; i++)
    {
        for (j=i+1; j<=4; j++)
            if (strcmp(a[i], a[j])>0)
            {
                strcpy(temp, a[i]);
                strcpy(a[i], a[j]);
                strcpy(a[j], temp);
            }
    }
    
    for (i=0; i<=4; i++)
        puts(a[i]);
    return 0;
}
