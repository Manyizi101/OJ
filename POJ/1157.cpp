#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define INF 10000

int dp[110][110];
int map[110][110];

int max(int a, int b)
{
    return a > b ? a : b;
}

int main(int argc, char const *argv[])
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &map[i][j]);
        }
    for (int i = 0; i <= n; i++)
        for (int j = 0; j < i; j++)
            dp[i][j] = -INF;
    for (int j = 1; j <= m; j++)
        for (int i = 1; i <= -max(-n, -j); i++)
        {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - 1] + map[i][j]);
        }
    printf("%d\n", dp[n][m]);
}