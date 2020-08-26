#include <stdio.h>

int main(void)
{
    int (*ptr)[2];
    int torf[2][2] = {12, 14, 16};
    ptr = torf;
    printf("%p\t%p\n", *ptr, *(ptr + 1));
    printf("%p\t%p\n", &torf[0][0], &torf[1][0]);
    printf("%p\t%p\n", torf[0], torf[1]);
    printf("%d\t%d\n", **ptr, **(ptr + 1));

    return 0;
}
