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

const int maxn = 30;

int n, t, b[maxn], a;
int ans = 0;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        ans = inf;
        scanf("%d%d", &n, &a);
        for (int i = 0; i < n; ++i)    scanf("%d", &b[i]);
        sort(b, b + n, cmp);
        for (int i = 0; i < (1 << n); ++i)
        {
            int Max = 0;
            int tmp = a;
            for (int j = 0; j < n; ++j)
            {
                if (i & (1 << j))
                {
                    Max++;
                    tmp %= b[j];
                }
            }
            if (tmp == 0)
                ans = min(Max, ans);
        }
        if (ans == inf)
            printf("%d\n", -1);
        else
            printf("%d\n", ans);
    }
    return 0;
}