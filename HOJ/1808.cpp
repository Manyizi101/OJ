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

const int MAXN = 100000 + 10;
int c, n, sum, s, e;
int a[MAXN], st[MAXN];

int main()
{
    ios::sync_with_stdio(false);
    while (cin >> c >> n)
    {
        memset(st, 0, sizeof(st));
        if (!c && !n)    break;
        for (int i = 1; i <= n; i++)    cin >> a[i];
        sum = 0;
        s = e = 1;
        for (int i = 1; i <= n; i++)
        {
            sum = (sum + a[i]) % c;
            if (!sum)
            {
                s = 1;
                e = i;
                break;
            }
            else if (st[sum])
            {
                s = st[sum] + 1;
                e = i;
                break;
            }
            else
            {
                st[sum] = i;
            }
        }
        for (int i = s; i <= e; i++)
        {
            cout << i << " ";
            if (i == e)    cout << endl;
        }
    }
    return 0;
}