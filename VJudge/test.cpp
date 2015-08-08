#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
#include<cstdio>
#include<vector>
#define pb push_back
#define debug puts("=====================");
using namespace std;
typedef long long ll;
const int N = 100;
ll dp[N][N];
ll ans[N];
int main ()
{
    freopen("test.out", "w", stdout);
    memset(dp, 0, sizeof(dp));
    int n;
    for (int i = 1; i <= 60; i++)
    {
        dp[i][1] = 1;
        for (int j = 2; j <= i; j++)
        {
            for (int k = 0; k < i - 2; k++)
            {
                dp[i][j] += dp[k][j - 1];
            }
        }
    }
    printf("{");
    for (int i = 1; i <= 60; i++)
    {
        ans[i] = 0;
        for (int j = 1; j <= i; j++)
        {
            for (int k = 1; k <= j; k++)
            {
                ans[i] += dp[j][k];
            }
        }
        printf("\"");
        cout << ans[i];
        printf("\",");
    }
    printf("}");
}
