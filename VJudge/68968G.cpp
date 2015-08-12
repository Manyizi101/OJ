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
    //点在线段上(结合判断点在线段上不含端点，可以用于判断是否为顶点相连接)
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
        return sgn(det(b - l.s, l.vec())) * sgn(det(a - l.s, l.vec())) > 0;
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

const int maxn =40+10;

int n;
bool vis[maxn];
point st;
vector<line> vec;
vector<double> p[4];

void pp(point a)
{
    if(a.x==0)  p[0].push_back(a.y);
    else if(a.x==100)   p[1].push_back(a.y);
    else if(a.y==0) p[2].push_back(a.x);
    else p[3].push_back(a.x);
}

/*
double multi(point p0,point p1,point p2)
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

bool is_inter(point s1,point e1,point s2,point e2)
{
    return (max(s1.x,e1.x)>=min(s2.x,e2.x))&&
           (max(s2.x,e2.x)>=min(s1.x,e1.x))&&
           (max(s1.y,e1.y)>=min(s2.y,e2.y))&&
           (max(s2.y,e2.y)>=min(s1.y,e1.y))&&
           (multi(s1,s2,e1)*multi(s1,e1,e2)>=0)&&
           (multi(s2,s1,e2)*multi(s2,e2,e1)>=0);
}
**/
int main()
{
    vec.clear();
    memset(p,0,sizeof(p));
    scanf("%d", &n);
    line tmp;
    for(int i=0; i<n; ++i)
    {
        tmp.in();
        vec.push_back(tmp);
        pp(tmp.s);
        pp(tmp.t);
    }
    st.in();
    int sum=0;
    int Min=inf;
    for(int i=0; i<4; ++i)
    {
        p[i].push_back(0);
        p[i].push_back(100);
        sort(p[i].begin(),p[i].end());
        sum=0;
        point it;
        for(int j=1; j<p[i].size(); j++)
        {
            if(i<2)
            {
                it.x=(i==0)?0:100;
                it.y=(p[i][j]+p[i][j-1])/2.0;
            }
            else
            {
                it.y=(i==2)?0:100;
                it.x=(p[i][j]+p[i][j-1])/2.0;
            }
            sum=0;
            for(int k=0; k<vec.size(); ++k)
            {
                if(issegxseg(line(st,it),vec[k]))   sum++;
                //if(is_inter(st,it,vec[k].s,vec[k].t))   sum++;
            }
            Min = min(Min,sum);
        }
    }
    printf("Number of doors = %d\n", Min+1);
}

