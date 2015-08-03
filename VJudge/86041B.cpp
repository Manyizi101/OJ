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

const int maxn = 1000 + 10;

int t, n;
ll a[maxn];
ll ans = 0;
int flag = 0;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        ans = 0;
        flag = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%I64d", &a[i]);
        }
        for (int i = 0; i < n; ++i)
        {
            if (a[i] > 1)
            {
                flag = i;
                break;
            }
        }
        for (int i = 0; i < flag; ++i)
        {
            if (a[i] == 1) ans++;
        }
        if (flag == 0 && !(n & 1) && a[0] == 1)  {printf("No\n"); continue;}
        if (!(ans & 1)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}