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

int t,n;
point a(0,0),b(1,1);
point x[20];
double ang[20];

const int maxn = 4;
double ans[maxn] = {0};
bool l[maxn];
inline int solve(double a[][maxn], bool l[], double ans[], const int& n) {
    int res = 0, r = 0;
    for (int i = 0; i < n; i++) l[i] = false;
    for (int i = 0; i < n; i++) {
        for (int j = r; j < n; j++)
            if (fabs(a[j][i]) > eps) {
                for (int k = i; k <= n; k++) swap(a[j][k], a[r][k]);
                break;
            }
        if (fabs(a[r][i]) < eps) {
            res++;
            continue;
        }
        for (int j = 0; j < n; j++)
            if (j != r && fabs(a[j][i]) > eps) {
                double tmp = a[j][i] / a[r][i];
                for (int k = i; k <= n; k++) a[j][k] -= tmp * a[r][k];
            }
        l[i] = true, r++;
    }
    for (int i = r; i < n; i++) if (fabs(a[i][n]) > eps) return -1;
    for (int i = 0; i < n; i++)
        if (l[i])
            for (int j = 0; j < n; j++)
                if (fabs(a[j][i]) > eps)
                    ans[i] = a[j][n] / a[j][i];
    return res;
}

double sum=0;

int main ()
{
    scanf("%d", &t);
    while(t--)
    {
        a = point(0,0);
        b = point(1,1);
        sum=0;
        scanf("%d", &n);
        for(int i=0;i<n;++i)
        {
            double tx,ty,tp;
            scanf("%lf%lf%lf",&tx,&ty,&tp);
            x[i].x=tx;
            x[i].y=ty;
            sum+=tp;
            a = a.rotate(x[i],tp);
            b = b.rotate(x[i],tp);
        }
        double cal[maxn][maxn] = {0};
        memset(cal,0,sizeof(cal));
        memset(ans,0,sizeof(ans));
        cal[0][0]=a.x;
        cal[0][1]=a.y;
        cal[0][2]=0.5*(a.x*a.x+a.y*a.y);
        cal[1][0]=b.x-1;
        cal[1][1]=b.y-1;
        cal[1][2]=0.5*(b.x*b.x+b.y*b.y-2);
        solve(cal,l,ans,2);
        while(sum>=2*acos(-1.0))   sum-=2*acos(-1.0);
        printf("%.8f %.8f %.8f\n",ans[0],ans[1], sum);
    }
    return 0;
}
