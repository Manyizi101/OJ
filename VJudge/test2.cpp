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

const int MAXN = 100 + 10;
int t, n, d;

struct Point
{
    double x, y;
    Point(int x = 0, int y = 0): x(x), y(y) {}
} e[MAXN], p[MAXN], ch[MAXN];
typedef Point Vector;

double cal(Point a, Point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
Vector operator - (Vector A, Vector B)
{
    return Vector(A.x - B.x, A.y - B.y);
}
int Cross(Vector A, Vector B)
{
    return A.x * B.y - A.y * B.x; //叉积
}
int cmp(Point a, Point b)
{
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

int ConvexHull(int n)//求凸包
{
    sort(p, p + n, cmp);
    int i, m = 0, k;
    for (i = 0; i < n; i++)
    {
        while (m > 1 && Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0)m--;
        ch[m++] = p[i];
    }
    k = m;
    for (i = n - 2; i >= 0; i--)
    {
        //cout<<"*"<<m<<endl;
        while (m > k && Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0)m--;
        ch[m++] = p[i];
    }
    if (n > 1)m--;
    return m;
}

int main()
{
    int cs = 0;
    scanf("%d", &t);
    while (t--)
    {
        double len = 0 ;
        scanf("%d%d", &n, &d);
        for (int i = 0; i < n; i++)
        {
            scanf("%lf%lf", &p[i].x, &p[i].y);
        }
        int num = ConvexHull(n);

        for (int i = 0; i < num - 1; i++)
        {
            len += cal(ch[i], ch[i + 1]);
        }
        len += cal(ch[num - 1], ch[0]);
        printf("Case #%d: ", ++cs);
        printf("%.4f\n", len / pi / (double)d);
    }
    return 0;
}