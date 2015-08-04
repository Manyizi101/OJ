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

const int maxn = 5000 + 10;

int n, m, cc = 0;

struct node
{
    double x, y;
    node (double a = 0, double b = 0)
    {
        x = a, y = b;
    }
} p[maxn], toy[maxn];

double U[maxn], L[maxn];
int res[maxn];

double crossProduct(node a, node b, node c)
{
    return (c.x - a.x) * (b.y - a.y) - (b.x - a.x) * (c.y - a.y);
}

int main()
{
    double x1, x2, y1, y2;
    int l, r, mid;
    while (~scanf("%d", &n) && n)
    {
        if (cc != 0)   printf("\n");
        cc = 1;
        scanf("%d%lf%lf%lf%lf", &m, &x1, &y1, &x2, &y2);
        for (int i = 0; i < n; ++i)
        {
            scanf("%lf%lf", U + i, L + i);
        }
        U[n] = L[n] = x2;
        for (int i = 0; i <= n; ++i)
        {
            for (int j = n; j >= 0; --j)
            {
                if (min(U[i], L[i]) > min(U[j], L[j]))
                {
                    swap(U[i], U[j]);
                    swap(L[i], L[j]);
                }
            }
        }
        // for (int i = 0; i <= n; i++)
        // {
        //     cout << U[i] << " " << L[i] << endl;
        // }
        memset(res, 0, sizeof(res));
        for (int i = 0; i < m; ++i)
        {
            scanf("%lf%lf", &p[i].x, &p[i].y);
            l = 0, r = n;
            while (l < r)
            {
                mid = (l + r) / 2;
                node b(L[mid], y2), c(U[mid], y1);
                if (crossProduct(b, p[i], c) > 0)
                {
                    r = mid;
                }
                else l = mid + 1;
            }
            mid = (l + r) / 2 ;
            res[mid]++;
        }
        for (int i = 0; i <= n; ++i)
        {
            printf("%d: %d\n", i, res[i]);
        }
    }
    return 0;
}