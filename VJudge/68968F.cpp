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

struct line
{
    point s, t;
    int id;
    line(const point &s = point(), const point &t = point()): s(s), t(t) {}
    point vec() const
    {
        return t - s;
    }
    double norm() const
    {
        return vec().norm();
    }
    //点在直线上(结合判断平行，可用于判断直线重合)
    bool ispointonline(const point &p) const
    {
        return sgn(det(p - s, t - s)) == 0;
    }
    //点在线段上
    bool ispointonseg(const point &p) const
    {
        return ispointonline(p) && sgn(dot(p - s, p - t)) <= 0;
    }
    //点在线段上不含端点
    bool ispointonsegex(const point &p)
    {
        return ispointonline(p) && sgn(dot(p - s, p - t)) < 0;
    }
    //点到直线的垂足
    point pointprojline(const point &p)
    {
        return s + vec() * ((dot(p - s, vec()) / norm()) / (norm()));
    }
    //点到直线的距离
    double pointdistline(const point &p)
    {
        return fabs(det(p - s, vec()) / norm());
    }
    //点到线段的距离
    double pointdistseg(const point &p)
    {
        if (sgn(dot(p - s, t - s)) < 0) return (p - s).norm();
        if (sgn(dot(p - t, s - t)) < 0) return (p - t).norm();
        return pointdistline(p);
    }
    //判断两直线是否平行
    friend bool parallel(const line &l1, const line &l2)
    {
        return !sgn(det(l1.vec(), l2.vec()));
    }
    //判断两个点是否在直线的同一侧
    friend bool sameside(const line &l, const point &a, const point &b)
    {
        return sgn(det(b - l.s, l.vec())) * sgn(det(a - l.s, l.vec())) >= 0;
    }
    //两直线的交点
    friend point linexline(const line l1, const line l2) //利用相似三角形对应边成比例
    {
        double s1 = det(l1.s - l2.s, l2.vec());
        double s2 = det(l1.t - l2.s, l2.vec());
        return (l1.t * s1 - l1.s * s2) / (s1 - s2);
    }
    //判断线段交
    friend bool issegxseg(const line &l1, const line &l2)
    {
        if (!sgn(det(l2.s - l1.s, l1.vec())) && !sgn(det(l2.t - l1.s, l1.vec())))
        {
            return l1.ispointonseg(l2.s) ||
                   l1.ispointonseg(l2.t) ||
                   l2.ispointonseg(l1.s) ||
                   l2.ispointonseg(l1.t);
        }
        return !sameside(l1, l2.s, l2.t) && !sameside(l2, l1.s, l1.t);
    }
    //直线沿法线方向移动d距离
    friend line move(const line &l, const double &d)
    {
        point t = l.vec();
        t = t / t.norm();
        t = t.rotate(pi / 2);
        return line(l.s + t * d, l.t + t * d);
    }
    int in()
    {
        s.in();
        return t.in();
    }
    void out()
    {
        s.out(), t.out();
    }
};

int n;

bool ispointonline(line l1, line l2)
{
    if(l1.ispointonseg(l2.s)&&!(l1.ispointonsegex(l2.s)&&!(l1.ispointonseg(l2.t))))    return true;
    if(l1.ispointonseg(l2.t)&&!(l1.ispointonsegex(l2.t)&&!(l1.ispointonseg(l2.s))))    return true;
    return false;
}

bool judge(line l1, line l2)
{
    //point on point
    if(ispointonline(l1,l2)||ispointonline(l2,l1))    return false;
    //cover
    if(parallel(l1,l2)&&(l1.ispointonseg(l2.s)||l1.ispointonseg(l2.t)))  return true;
    //croess
    return !sameside(l1, l2.s, l2.t) && !sameside(l2, l1.s, l1.t);
}

int main()
{    while (~scanf("%d", &n) && n)
    {
        queue<line> ans;
        for (int i = 0; i < n; ++i)
        {
            line x;
            x.in();
            x.id = i + 1;
            unsigned len = ans.size();
            for (unsigned j = 0; j < len; ++j)
            {
                if (!judge(x,ans.front()))
                {
                    ans.push(ans.front());
                }
                ans.pop();
            }
            ans.push(x);
        }
        printf("Top sticks: ");
        for (unsigned i = 0; i < ans.size()-1; ++i)
        {
            printf("%d, ", ans.front().id);
            ans.pop();
        }
        printf("%d.\n", ans.front().id);
        ans.pop();
    }
}
