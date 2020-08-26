// 快速幂
#include <stdio.h>
#define MOD 10


typedef long long ll;
ll qpow(ll a, ll n);
int main(void)
{
    int a, n;
    long int res;

    while (scanf("%d %d", &a, &n) == 2) {
        res = qpow(a, n);
        printf("%ld\n", res);
    }

    return 0;
}

ll qpow(ll a, ll n)
{
    if (n == 0)
        return 1;
    else if (n % 2 == 1)
        return qpow(a, n - 1) * a % MOD;
    else
    {
        ll temp = qpow(a, n / 2) % MOD;
        return temp * temp % MOD;
    }
}