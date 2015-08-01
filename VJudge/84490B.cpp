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

const int maxn = 50 + 10;

int t, n, a[maxn];
float b[maxn * 3];
int len = 0;
float ans;

bool judge(int x)
{
    float seg = b[x];
    for (int i = 2; i <= n - 1; ++i)
    {
        if (seg == (float)a[i])    continue;
        else if(seg<=(float)a[i]-x)     seg=(float)a[i];
        else if((float)a[i])
    }
    return true;
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        len = 0;
        scanf("%d%d", &n, &a[0]);
        for (int i = 1; i < n; ++i)
        {
            scanf("%d", &a[i]);
            b[len++] = abs(a[i] - a[i - 1]);
            b[len++] = abs(a[i] - a[i - 1]) * 1.0 / 2;
        }
        sort(b, b + len);
        for (int i = len - 1; i >= 0; --i)
        {
            if (judge(i))
            {
                ans = b[i];
                break;
            }
        }
        printf("%.3f\n", ans);
    }
    return 0;
}