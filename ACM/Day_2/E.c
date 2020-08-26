#include <stdio.h>

int min_num(int x, int y);
int nums[10005] = {0};
int n;
int temp;

int main(void)
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    for (int i = 0; i < n - 1; i++)
        for (int j = i+1; j < n; j++)
            if (nums[i] > nums[j]) {
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }

    printf("%d\n", min_num(nums[n - 1] - nums[1], nums[n - 2] - nums[0]));

    return 0;
}

int min_num(int x, int y)
{
    if (x<y)
        return x;
    else
        return y;
}