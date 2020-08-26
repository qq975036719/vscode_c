#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int n=0, m=0, i;

    for (i=0; i<=10000000; i++)
        {
            double x = 1.0 * rand() / RAND_MAX;
            double y = 1.0 * rand() / RAND_MAX;
            if (x*x + y*y <= 1.0) n++;
            m++;
        }
        printf("%lf\n", 4.0 * n / m);
    getchar();
    return 0;
}
