#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, x;
    int nums[101] = {0};
    int max = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        nums[x]++;
    }

    for (int i = 0; i < 101; i++) {
        if (nums[i]>max)
            max = nums[i];
    }
    printf("%d", max);

    return 0;
}