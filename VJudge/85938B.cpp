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

const int maxn = 10;

int a[1 << maxn], n, m, k;
int b[maxn];
int x[maxn];

int main()
{
    k = 0;
    while (~scanf("%d", &n) && n)
    {
        printf("S-Tree #%d:\n", ++k);
        for (int i = 0; i < n; ++i)
        {
            getchar();
            getchar();
            scanf("%d", &b[i]);
        }
        for (int i = 0; i < (1 << n); ++i)
            scanf("%1d", &a[i]);
        scanf("%d", &m);
        while (m--)
        {
            int val = 0;
            char tmp[maxn];
            scanf("%s", tmp + 1);
            for (int j = 0; j < n; ++j)
            {
                x[b[j]] = tmp[b[j]] - '0';
            }
            for (int j = 0; j < n; ++j)
            {
                val += (x[b[j]] << (n - j - 1));
                //cout << (x[b[j]] << (n - j - 1)) << endl;
            }
            cout << a[val];
        }
        cout << endl << endl;
    }
    return 0;
}