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

//返回坐标的平方
inline double sqr(const double &x)
{
    return x * x;
}
//返回坐标的正负
inline int sgn(const double &x)
{
    return x < -eps ? -1 : x > eps;
}

struct point
{
    double x, y;
    point(const double &x = 0, const double &y = 0): x(x), y(y) {}
    friend point operator + (const point &a, const point &b)
    {
        return point(a.x + b.x, a.y + b.y);
    }
    friend point operator - (const point &a, const point &b)
    {
        return point(a.x - b.x, a.y - b.y);
    }
    friend point operator * (const point &a, const double &b)
    {
        return point(a.x * b, a.y * b);
    }
    friend point operator * (const double &a, const point &b)
    {
        return point(a * b.x, a * b.y);
    }
    friend point operator / (const point &a, const double &b)
    {
        return point(a.x / b, a.y / b);
    }
    friend bool operator == (const point &a, const point &b)
    {
        return !sgn(a.x - b.x) && !sgn(a.y - b.y);
    }
    friend bool operator < (const point &a, const point &b)
    {
        return sgn(a.x - b.x) < 0 || (sgn(a.x - b.x) == 0 && sgn(a.y - b.y) < 0);
    }
    //返回点到原点的距离
    double norm()
    {
        return sqrt(sqr(x) + sqr(y));
    }
    //返回两个点的外积
    friend double det(const point &a, const point &b)
    {
        return a.x * b.y - a.y * b.x;
    }
    //返回两个点的内积
    friend double dot(const point &a, const point &b)
    {
        return a.x * b.x + a.y * b.y;
    }
    //返回两个点之间线段的长度
    friend double dist(const point &a, const point &b)
    {
        return (a - b).norm();
    }
    //返回两点构成的直线的仰角
    double arg()
    {
        return atan2(y, x);
    }
    //逆时针旋转angle弧度
    point rotate(const double &angle)
    {
        return rotate(cos(angle), sin(angle));
    }
    point rotate(const point &p, const double &angle)
    {
        return (*this - p).rotate(angle) + p;
    }
    point rotate(const double &cosa, const double &sina)
    {
        return point(x * cosa - y * sina, x * sina + y * cosa);
    }
    int in()
    {
        return scanf("%lf %lf", &x, &y);
    }
    void out()
    {
        //输出默认采用两位小数，注意修改
        printf("%.2f %.2f\n", x, y);
    }
};

const int maxn = 20;

int n;
point l[maxn][maxn];
double x, y;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &x);
        for (int j = 0; j < m; ++j)
        {
            scnaf()
        }
    }
    return 0;
}