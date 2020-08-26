#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[50];
    scanf("%[^\n]s", str);
    printf("%s", str);

    return 0;
}
