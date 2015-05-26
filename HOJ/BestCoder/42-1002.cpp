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
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;

typedef long long int ll;
int n, m;
map<ll, vector<int> > mp;
map<ll, int> vis;
ll tmp;

void read(ll &x)
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
    while (~scanf("%d%d", &n, &m))
    {
        mp.clear();
        vis.clear();
        for (int i = 1; i <= n; i++)
        {
            read(tmp);
            mp[tmp].push_back(i);
        }
        for (int i = 1; i <= m; i++)
        {
            read(tmp);
            int sz = mp[tmp].size();
            if (sz == 0 || vis[tmp] == sz)
            {
                cout << -1 << endl;
            }
            else
            {
                cout << mp[tmp][vis[tmp]] << endl;
                vis[tmp]++;
            }
        }
    }
    return 0;
}