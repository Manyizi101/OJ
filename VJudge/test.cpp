#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <set>
//#include <map>
#include <queue>
#include <utility>
#include <stack>
#include <list>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <ctype.h>
using namespace std;

struct point {   //点的结构
    double x, y;
    point (double a = 0, double b = 0)
    {
        x = a, y = b;
    }
} p[5005];
double U[5005], L[5005];
int res[5005];

double multi (point a, point b, point c)    //叉积判断点线关系
{
    double x1, y1, x2, y2;
    x1 = b.x - a.x;
    y1 = b.y - a.y;
    x2 = c.x - b.x;
    y2 = c.y - b.y;
    return x1 * y2 - x2 * y1;
}

int main()
{
    int n, i, m, l, r, mid, cc = 1;
    double x1, y1, x2, y2;
    while (scanf ("%d", &n), n)
    {
        if (cc == 2)
            printf ("\n");
        cc = 2;
        scanf ("%d%lf%lf%lf%lf", &m, &x1, &y1, &x2, &y2);
        for (i = 0; i < n; i++)
            scanf ("%lf%lf", U + i, L + i); //输入分割线的上端+下端的横坐标
        U[n] = L[n] = x2;    //加最后一条边（矩型的右边），二分有用
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

        /***********************************华丽的分割线***********************************/

        //下面是利用 叉积+二分 查找点所在位置，二分太强大了
        memset (res, 0, sizeof(res));
        for (i = 0; i < m; i++)
        {
            scanf ("%lf%lf", &p[i].x, &p[i].y);    //输入要找的点
            l = 0, r = n;
            while (l < r)
            {
                mid = (l + r) / 2;
                point b(L[mid], y2), c(U[mid], y1);    //第mid条分割线bc
                if (multi (p[i], b, c) > 0)
                    r = mid;
                else l = mid + 1;
            }
            mid = (l + r) / 2;
            res[mid]++;    //得知此点在第mid个区间
        }
        for (i = 0; i <= n; i++)
            printf ("%d: %d\n", i, res[i]);
    }
    return 0;
}
