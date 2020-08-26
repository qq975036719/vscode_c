#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int x;
    int y;
} coordinate;


int main(void)
{
    int n = 10;
    int k = 2;
    coordinate *temp = (coordinate *)malloc((n - k + 1) * sizeof(coordinate));

    for (int i = 0; i < (n - k + 1); i++)
    {
        temp[i].x = i;
        temp[i].y = i;
        printf("%d %d\n", temp[i].x, temp[i].y);
    }

    return 0;
}