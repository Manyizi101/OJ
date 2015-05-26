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
const int MAXN = 1000 + 10;

int t, n, m;
int flag = 0;
int a[MAXN][4], b[MAXN][4];
ll c[MAXN];
int num;
char tmp[MAXN];

void init()
{
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", tmp);
        sscanf(tmp, "%d.%d.%d.%d", &a[i][0], &a[i][1], &a[i][2], &a[i][3]);
        //cout << a[i][0] << '.' << a[i][1] << '.' << a[i][2] << '.' << a[i][3] << endl;
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%s", tmp);
        sscanf(tmp, "%d.%d.%d.%d", &b[i][0], &b[i][1], &b[i][2], &b[i][3]);
    }
}

bool judge(ll x)
{
    for (int i = 0; i < num; i++)
    {
        if (x == c[i]) return false;
    }
    return true;
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        cout << "Case #" << ++flag << ":" << endl;
        init();
        for (int i = 0; i < m; i++)
        {
            memset(c, 0, sizeof(c));
            num = 0;
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    c[num] = c[num] * 1000 +  (b[i][k] & a[j][k]);
                }
                if (judge(c[num]))   num++;
                else c[num] = 0;
            }
            cout << num << endl;
        }
    }
    return 0;
}