#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    int *p1 = (int *)malloc(100 * sizeof(int));
    int *p2 = (int *)calloc(100, sizeof(int));

    for (int i = 0; i < 100; i++)
        printf("%d %d\n", p1[i], p2[i]);

    free(p1);
    free(p2);

    printf("请按任意键继续...\n");
    getchar();

    return 0;
}