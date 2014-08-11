#include <iostream>
#include <cstdio>
#include <math.h>
#include <cstring>
#include <cstdlib>
#define INF 1000000000

using namespace std;

int d[305];
int dp[35][305], dis[305][305];
int n, m;

void init()
{
    memset(dis, 0, sizeof(dis));
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
        {
            int mid = (i + j) >> 1;
            for (int k = i; k <= j; ++k)
                dis[i][j] += abs(d[k] - d[mid]);
        }
}

void DP()
{
    for (int i = 1; i <= n; ++i)
        dp[1][i] = dis[1][i];
    for (int i = 2; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            dp[i][j] = INF;
    for (int i = 2; i <= m; i++)
        for (int j = i; j <= n; ++j)
            for (int k = 1; k <= j; ++k)
            {
                if (dp[i][j] > dp[i - 1][k] + dis[k + 1][j])
                    dp[i][j] = dp[i - 1][k] + dis[k + 1][j];
            }
    printf("%d\n", dp[m][n]);
}

int main(int argc, char const *argv[])
{
    while (scanf("%d%d", &n, &m) != EOF)
    {
        for (int i = 1; i <= n; ++i)   scanf("%d", &d[i]);
        init();
        DP();
    }
    return 0;
}