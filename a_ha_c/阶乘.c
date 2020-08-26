#include<stdio.h>
#include<stdlib.h>
int main()
{
int n;
int i;
scanf("%d", &n);
i = n-1;
while (i!=1) {
    n = n*i;
    i--;
    }
printf("%d", n);
return 0;

}
