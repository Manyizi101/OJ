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

typedef long long int ll;
const double pi = acos(-1.0);
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
using namespace std;

string g;

const int maxn = 2 * 1e5 + 10;

int t, n, a[maxn];
ll ans = 0;;
int cs = 0;
ll dp[maxn][2];
int preb, b;
ll Max;

inline int cal(int preb, int x)
{
    if (preb == -1)    return 1;
    else return preb ^ x;
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        memset(dp,0,sizeof(dp));
        cin >> g;
        n = g.size();
        for (int i = 0; i < n; ++i)    scanf("%d", &a[i]);
        preb = 0;
        if (g[0] == '0')
        {
            dp[0][0] = 0;
            dp[0][1] = a[0];
        }
        else if (g[0] == '1')
        {
            dp[0][0] = a[0];
            dp[0][1] = 0;
        }
        else
        {
            dp[0][0] = (cal(preb, 0)) ? a[0] : 0;
            dp[0][1] = (cal(preb, 1)) ? a[0] : 0;
        }
        for (int i = 1; i < n; ++i)
        {
            Max = max(dp[i - 1][0], dp[i - 1][1]);
            if (g[i] == '0')
            {
                b = cal(preb, 0);
                dp[i][0] = Max + (b ? a[i] : 0);
                dp[i][1] = Max;
                preb = b;
            }
            else if (g[i] == '1')
            {
                b = cal(preb, 1);
                dp[i][0] = Max;
                dp[i][1] = Max + (b ? a[i] : 0);
                preb = b;
            }
            else if(g[i]=='?')
            {
                dp[i][0] = Max + ((cal(preb, 0)) ? a[i] : 0);
                dp[i][1] = Max + ((cal(preb, 1)) ? a[i] : 0);
                preb = -1;
            }
            //cout<<b<<endl;
            cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
        }
        printf("%I64d\n", max(dp[n-1][0], dp[n-1][1]));
    }
}





























































