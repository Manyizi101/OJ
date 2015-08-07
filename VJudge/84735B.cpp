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

int n, len;
vector<int> a;
int ans[maxn];

int main()
{
    while (~scanf("%d", &n))
    {
        a.clear();
        int tmp = 0;
        len = 0;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &tmp);
            a.push_back(tmp);
        }
        sort(a.begin(), a.end());
        for (unsigned i = 0; i < a.size(); ++i)
        {
            if (a[i] & 1)
            {
                ans[len++] = a[i];
                a.erase(a.begin() + i);
                break;
            }
        }
        if (len == 0 || a[a.size() - 1] == 0)
        {
            printf("-1\n");
        }
        else
        {
            for (unsigned i = 0; i < a.size(); ++i)
            {
                ans[len++] = a[i];
            }
            int i = 0;
            for (i = len - 1; i >= 0; --i)
            {
                if (ans[i] != 0) break;
            }
            for (; i >= 0; --i)
            {
                printf("%d", ans[i]);
            }
            printf("\n");
        }
    }
    return 0;
}