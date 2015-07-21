#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ctype.h>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define eps 1e-8
#define INF 0x7fffffff
#define maxn 100005
#define PI acos(-1.0)
using namespace std;
typedef long long LL;
const int mod = 1000000007;
int a[101000];
int vis[101100];
int l[111110], r[111110];
int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        memset(vis, 0, sizeof(vis));
        for (int  i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            l[i] = 0;
            int num  = 0;
            for (int j = 1; j <= sqrt(a[i]) + 1; j++)
            {
                if (a[i] % j == 0 )
                {
                    l[i] = max(l[i], vis[j] + 1);
                    l[i] = max(l[i], vis[a[i] / j] + 1);
                }

            }
            vis[a[i]] = i;
        }
        for (int i = 0; i <= 10000; i++) vis[i] = n + 1;
        for (int i = n; i >= 1; i--)
        {
            int num = 0;
            r[i] = n + 1;
            for (int j = 1; j <= sqrt(a[i]); j++)
            {
                if (a[i] % j == 0 )
                {
                    r[i] = min(r[i], vis[j] - 1);
                    r[i] = min(r[i], vis[a[i] / j] - 1);
                }

            }
            vis[a[i]] = i;
        }
        for (int i = 1; i <= n; i++)
        {
            ans = ans + (r[i] - i + 1) * (i - l[i] + 1) % mod;
            //cout<<l[i]<<"   "<<r[i]<<endl;
        }
        ans %= mod;
        printf("%d\n", ans);
    }

}
