#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    double num;
    char str[100];

    scanf("%lf%d", &num, &n);
    sprintf(str, "%%.%dlf", n);
    printf(str, num);
}
