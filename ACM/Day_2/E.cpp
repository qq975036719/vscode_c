#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 10;
int nums[maxn];
int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);
    sort(nums, nums + n);
    printf("%d\n", min(nums[n - 1] - nums[1], nums[n - 2] - nums[0]));

    return 0;
}