#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100010 * 5;
const double pi = atan(1.0) * 4;

struct node {
    int x, y;
} e[maxn], res[maxn], e1[maxn], res1[maxn];

int cmp(node a, node b)
{
    if (a.x == b.x)return a.y < b.y;
    return a.x < b.x;
}
int cross(node a, node b, node c) //向量积
{
    return (a.x - c.x) * (b.y - c.y) - (b.x - c.x) * (a.y - c.y);
}
int convex(int n, node e[], node res[]) //求凸包上的点
{
    sort(e, e + n, cmp);
    int m = 0, i, j, k;
    //求得下凸包，逆时针
    //已知凸包点m个，如果新加入点为i，则向量(m-2,i)必定要在(m-2,m-1)的逆时针方向才符合凸包的性质
    //若不成立，则m-1点不在凸包上。
    for (i = 0; i < n; i++)
    {
        while (m > 1 && cross(res[m - 1], e[i], res[m - 2]) <= 0)m--;
        res[m++] = e[i];
    }
    k = m;
    //求得上凸包
    for (i = n - 2; i >= 0; i--)
    {
        while (m > k && cross(res[m - 1], e[i], res[m - 2]) <= 0)m--;
        res[m++] = e[i];
    }
    if (n > 1)m--; //起始点重复。
    return m;
}

double lenght(node a, node b)
{
    return sqrt(1.0 * (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        int i, j, k, m, cnt = 0;
        for (i = 0; i < n; i++)
        {
            int tx, ty;
            scanf("%d%d", &tx, &ty);
            e[cnt].x = tx, e[cnt++].y = ty;
        }
        m = convex(cnt, e, res);
        cnt = 0;
        for (i = 0; i < m; i++)
        {
            e1[cnt].x = res[i].x, e1[cnt++].y = res[i].y;
            e1[cnt].x = res[i].x - 1, e1[cnt++].y = res[i].y;
            e1[cnt].x = res[i].x + 1, e1[cnt++].y = res[i].y;
            e1[cnt].x = res[i].x, e1[cnt++].y = res[i].y - 1;
            e1[cnt].x = res[i].x, e1[cnt++].y = res[i].y + 1;
        }
        int x = convex(cnt, e1, res1);
        double ans = 0;
        for (i = 1; i < x; i++)
            ans += lenght(res1[i], res1[i - 1]);
        ans += lenght(res1[x - 1], res1[0]);
        printf("%.5f\n", ans);
    }
    return 0;
}