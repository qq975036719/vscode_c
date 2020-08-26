#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    double x;

    srand(time(0));
    
    scanf("%lf", &x);
    for (int i = 0; i < 100; i++) {
        printf("%lf\n", rand() * x / RAND_MAX);
    }

    return 0;
}