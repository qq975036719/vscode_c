#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[1009];
int main(void)
{
    int n;
    int num[1009];
    while (scanf("%d", &n)!=EOF) {
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++)
            scanf("%d", &num[i]);
        dp[1] = 1;
        int maxx = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = 1;
            for (int j = 1; j < i; j++) {
                if (num[i] > num[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    maxx = max(maxx, dp[i]);
                }
            }
        }
        printf("%d\n", maxx);
    }
}
