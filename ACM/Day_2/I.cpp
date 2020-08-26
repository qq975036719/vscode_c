#include<cstring>
#include<iostream>

#include<cstdio>

#include<algorithm>

using namespace std;

int n,m;

int v[1000 +5];

int dp[1000 + 5];

int main()

{

    while(~scanf("%d",&n) ) {

        if(n == 0 ) break;

        memset(dp,0,sizeof(dp));

        for(int i = 1; i<=n; i++) {

            cin>>v[i];

        }

        cin>>m;

        sort(v+1,v+n+1);

        m-=5;

        if(m < 0) {

            printf("%d\n",m+5);

            continue;

        }

        for(int i = 1; i<n; i++) {

            for(int j = m; j>=v[i]; j--) {

                dp[j] = max(dp[j], dp[j - v[i] ] + v[i]);

            }

        }

 //       printf("**%d***%d\n",m,dp[n-1],dp[n]);

        printf("%d\n",m+5 - dp[m] - v[n]);

 

    }

 

    return 0 ;

}