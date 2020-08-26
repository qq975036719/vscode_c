#include <stdio.h>

int main(void)
{
    int n;
    char st[60];
    int i = 0;
    int j = 0;

    scanf("%d", &n);
    scanf("%s", st);

    while (st[i] != '\0') {
        printf("%c", st[i]);
        j++;
        i += j;
    }
    return 0;
}