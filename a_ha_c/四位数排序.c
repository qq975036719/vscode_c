#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c, d, t;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if (a < b) {
        t = b;
        b = a;
        a = t;
    }
    if (a < c) {
        t = c;
        c = a;
        a = t;
    }
    if (a < d) {
        t = d;
        d = a;
        a = t;
    }
    if (b < c) {
        t = c;
        c = b;
        b = t;
    }
    if (b < d) {
        t = d;
        d = b;
        b = t;
    }
    if (c < d) {
        t = d;
        d = c;
        c = t;
    }
    printf("%d %d %d %d", a, b, c, d);
    return 0;
}
