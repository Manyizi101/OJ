#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <fstream>
#define debug puts("-----")
using namespace std;
typedef long long LL;
const double INF = 1e40;
const double eps  =1e-8;
const int N = 60105;
long dp[2][50][5][5],a[N],base[N];
void read(LL &x)
{
    char ch = getchar();
    int tag = 1;
    x = 0;
    while ((ch < '0' || ch > '9') && ch != '-')
    {
        ch = getchar();
    }

    if (ch == '-')
    {
        tag = -1;
        ch = getchar();
    }

    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - 48;
        ch = getchar();
    }

    x *= tag;
}
int main()
{
    int T,n,cs = 1;
    base[0]  =1;
    for(int i = 1;i<=40;i++) base[i] = base[i-1] * 2;
    scanf("%d",&T);
    while(T--)
    {
        memset(dp,0,sizeof(dp));
        double ans1 = 0,ans2 = 0,ans3 = 0;
        scanf("%d",&n);
        LL tot = n*(n+1)/2;
        for(int i = 0; i < n ; i++) read(a[i]);
        for(int i = 0 ; i<n; i++)
        {
            for(int j = 0; j<35; j++) dp[i%2][j][0][0] = dp[i%2][j][1][0] = 0;
            for(int j = 0; j<35; j++)
            {
                if(a[i] & base[j])
                {
                    dp[i%2][j][0][0] = dp[(i+1)%2][j][0][0];
                    dp[i%2][j][1][0] = dp[(i+1)%2][j][1][0] + 1;

                    dp[i%2][j][0][1] = 0;
                    dp[i%2][j][1][1] = dp[(i+1)%2][j][1][1] + dp[(i+1)%2][j][0][1] + 1;

                    dp[i%2][j][0][2] = dp[(i+1)%2][j][1][2];
                    dp[i%2][j][1][2] = dp[(i+1)%2][j][0][2] + 1;
                }
                else
                {
                    dp[i%2][j][0][0] = dp[(i+1)%2][j][0][0] + dp[(i+1)%2][j][1][0] + 1;
                    dp[i%2][j][1][0] = 0;

                    dp[i%2][j][0][1] = dp[(i+1)%2][j][0][1] + 1;
                    dp[i%2][j][1][1] = dp[(i+1)%2][j][1][1];

                    dp[i%2][j][0][2] = dp[(i+1)%2][j][0][2] + 1;
                    dp[i%2][j][1][2] = dp[(i+1)%2][j][1][2] ;
                }
            }
            for(int j = 0; j<35; j++)
            {
                ans1 += 1.0*dp[i%2][j][1][0]*base[j];
                ans2 += 1.0*dp[i%2][j][1][1]*base[j];
                ans3 += 1.0*dp[i%2][j][1][2]*base[j];
            }
        }
        printf("Case #%d: %.6f %.6f %.6f\n",cs++,ans1/tot,ans2/tot,ans3/tot);
    }
    return 0;
}
