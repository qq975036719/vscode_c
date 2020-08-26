#include <stdlib.h>
#include <stdio.h>

int main()
{
    int str1[1000], str2[1000];
    scanf("%s%s", &str1, &str2);
    printf("str1=%s\tstr2=%s\n", str1, str2);

    // strlen()
    sprintf(str1, "%s", str1);

    // strcpy()
    sprintf(str1, "%s", str2);

    printf("str1=%s\tstr2=%s\n", str1, str2);

    // strcat()
    sprintf(str1, "%s%s", str1, str2);

    printf("str1=%s\tstr2=%s\n", str1, str2);

    return 0;
}
