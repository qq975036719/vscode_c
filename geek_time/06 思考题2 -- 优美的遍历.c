#include <stdlib.h>
#include <stdio.h>

int main()
{
    char str[1000];
    scanf("%s", str);

    for(int i=0; str[i]; i++)
        printf("%c\n", str[i]);

    return 0;
}
