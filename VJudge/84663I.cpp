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

const int MAXN = 10000;

int vis[MAXN];

int main()
{
    int a, b;
    while (~scanf("%d%d", &a, &b))
    {
        memset(vis, -1, sizeof(vis));
        vector<int> ans;
        printf("%d/%d = %d.", a, b, a / b);
        a %= b;
        int cnt = 0, st, ed;
        while (true)
        {
            if (vis[a] != -1)
            {
                st = vis[a];
                ed = cnt;
                break;
            }
            vis[a] = cnt++;
            a *= 10;
            ans.push_back(a / b);
            a %= b;
        }
        for (int i = 0; i < st; i++) printf("%d", ans[i]);
        putchar('(');
        for (int i = st; i < min(ed, 50); i++) printf("%d", ans[i]);
        if (ed > 50) printf("...)");
        else putchar(')');
        puts("");
        printf("   %d = number of digits in repeating cycle\n\n", ed - st);
    }
    return 0;
}