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

const int maxn = 100 + 10;


int n, a[maxn], b[maxn * maxn];
ll ans;
int flag = 0;

int main()
{
    while (~scanf("%d", &n))
    {
        flag = 0;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                b[flag++] = a[i] + a[j];
            }
        }
        sort(b, b + flag);
        ans = b[0];
        for (int i = 1; i < flag; ++i)
        {
            if (b[i] == b[i - 1])   continue;
            else ans += b[i];
        }
        printf("%I64d\n", ans);
    }
    return 0;
}