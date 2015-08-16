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

const int maxn = 1000+10;

int t,n;
int a[maxn],d[maxn], c[maxn], cas, ans;

int main()
{
    scanf("%d", &cas);
    while (cas--)
    {
        scanf("%d", &n);
        int sum = ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &a[i]);
            d[i] = 1, c[i] = 1;
            for (int j = 1; j < i; ++j)
            {
                if (a[j] >= a[i]) continue;
                if (d[j] + 1 > d[i])
                {
                    d[i] = d[j] + 1;
                    c[i] = c[j];
                }
                else if (d[j] + 1 == d[i])    c[i] = 2;
            }
            if(d[i] > ans) ans = d[i];
        }
        for (int i = 1; i <= n; ++i)
            if (d[i] == ans)  sum += c[i];
        printf("%d\n", sum > 1 ? ans : ans - 1);
    }
    return 0;
}
