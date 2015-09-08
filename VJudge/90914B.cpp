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

const int maxn = 1e5+10;

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
        return a.x<b.x;
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


int t,n,q;

point a[maxn];
vector<point> l,r;
point x,tmp;

int cs = 1;

double cal(int id)
{
    return fabs(atan(a[id].y/(a[id].x-x.x)))*180/pi;
}

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

struct polygon
{
#define next(i) ((i+1)%n)
    int n;
    vector<point> p;
    polygon(int n = 0): n(n)
    {
        p.resize(n);
    }
//    polygon(vector<point> &v):p(v){}
    //多边形周长
    double perimeter()
    {
        double sum = 0;
        for (int i = 0; i < n; i++)
            sum += (p[next(i)] - p[i]).norm();
        return sum;
    }
    //多边形面积
    double area()
    {
        double sum = 0;
        for (int i = 0; i < n; i++)
            sum += det(p[i], p[next(i)]);
        return sum / 2 + eps; //要加eps吗？
    }
    //判断点与多边形的位置关系，0外, 1内,2边上
    int pointin(const point &t)
    {
        int num = 0;
        for (int i = 0; i < n; i++)
        {
            if (line(p[i], p[next(i)]).ispointonseg(t))
                return 2;
            int k = sgn(det(p[next(i)] - p[i], t - p[i]));
            int d1 = sgn(p[i].y - t.y);
            int d2 = sgn(p[next(i)].y - t.y);
            if (k > 0 && d1 <= 0 && d2 > 0) num++;
            if (k < 0 && d2 <= 0 && d1 > 0) num--;
        }
        return num != 0;
    }
    //多边形重心
    point masscenter()
    {
        point ans;
        if (sgn(area()) == 0) return ans;
        for (int i = 0; i < n; i++)
            ans = ans + (p[i] + p[next(i)]) * det(p[i], p[next(i)]);
        return ans / area() / 6 + eps; //要加eps吗？
    }
    //多边形边界上格点的数量
    int borderpointnum()
    {
        int num = 0;
        for (int i = 0; i < n; i++)
        {
            int a = fabs(p[next(i)].x - p[i].x);
            int b = fabs(p[next(i)].y - p[i].y);
            num += __gcd(a, b);
        }
        return num;
    }
    //多边形内格点数量
    int insidepointnum()
    {
        return int(area()) + 1 - borderpointnum() / 2;
    }
    void in()
    {
        for (int i = 0; i < n; i++)
            p[i].in();
    }
    void out()
    {
        for (int i = 0; i < n; i++)
            p[i].out();
    }
};

struct convex : public polygon
{
    convex(int n = 0): polygon(n) {}
//    convex(vector<point> &v):polygon(v){}
    //需要先求凸包，若凸包每条边除端点外都有点，则可唯一确定凸包
    bool isunique(vector<point> &v)
    {
        if (sgn(area()) == 0)
            return 0;
        for (int i = 0; i < n; i++)
        {
            line l(p[i], p[next(i)]);
            bool flag = 0;
            for (int j = 0; j < v.size(); j++)
                if (l.ispointonsegex(v[j]))
                {
                    flag = 1;
                    break;
                }
            if (!flag)
                return 0;
        }
        return 1;
    }
    //O(n)时间内判断点是否在凸包内
    bool containon(const point &a)
    {
        int sign = 0;
        for (int i = 0; i < n; i++)
        {
            int x = sgn(det(p[i] - a, p[next(i)] - a));
            if (x)
            {
                if (sign)
                {
                    if (sign != x)
                        return 0;
                }
                else
                    sign = x;
            }
        }
        return 1;
    }
    //O(logn)时间内判断点是否在凸包内
    bool containologn(const point &a)
    {
        point g = (p[0] + p[n / 3] + p[2 * n / 3]) / 3.0;
        int l = 0, r = n;
        while(l + 1 < r)
        {
            int m = (l + r) / 2;
            if (sgn(det(p[l] - g, p[m] - g)) > 0)
            {
                if (sgn(det(p[l] - g, a - g)) >= 0 && sgn(det(p[m] - g, a - g)) < 0)
                    r = m;
                else
                    l = m;
            }
            else
            {
                if (sgn(det(p[l] - g, a - g)) < 0 && sgn(det(p[m] - g, a - g)) >= 0)
                    l = m;
                else
                    r = m;
            }
        }
        return sgn(det(p[r % n] - a, p[l] - a)) - 1;
    }
    //最远点对（直径）
    int first, second; //最远的两个点对应标号
    double diameter()
    {
        double mx = 0;
        if (n == 1)
        {
            first = second = 0;
            return mx;
        }
        for (int i = 0, j = 1; i < n; i++)
        {
            while(sgn(det(p[next(i)] - p[i], p[j] - p[i]) -
                      det(p[next(i)] - p[i], p[next(j)] - p[i])) < 0)
                j = next(j);
            double d = dist(p[i], p[j]);
            if (d > mx)
            {
                mx = d;
                first = i;
                second = j;
            }
            d = dist(p[next(i)], p[next(j)]);
            if (d > mx)
            {
                mx = d;
                first = next(i);
                second = next(j);
            }
        }
        return mx;
    }
    //凸包是否与直线有交点O(log(n)), 需要On的预处理, 适合判断与直线集是否有交点
    vector<double> ang; //角度
    bool isinitangle;
    int finda(const double &x)
    {
        return upper_bound(ang.begin(), ang.end(), x) - ang.begin();
    }
    double getangle(const point &p) //获取向量角度[0, 2pi]
    {
        double res = atan2(p.y, p.x);   //(-pi, pi]
//        if (res < 0) res += 2 * pi; //为何不可以
        if(res < -pi / 2 + eps) res += 2 * pi; //eps修正精度
        return res;
    }
    void initangle()
    {
        for(int i = 0; i < n; i++)
            ang.push_back(getangle(p[next(i)] - p[i]));
        isinitangle = 1;
    }
    bool isxline(const line &l)
    {
        if(!isinitangle) initangle();
        int i = finda(getangle(l.t - l.s));
        int j = finda(getangle(l.s - l.t));
        if(sgn(det(l.t - l.s, p[i] - l.s) * det(l.t - l.s, p[j] - l.s) >= 0))
            return 0;
        return 1;
    }
};

bool cmpl(point a, point b)
{
    return a.x>b.x;
}

bool cmpr(point a, point b)
{
    return a.x<b.x;
}

convex convexhull(vector<point> &a, int flag)
{
    //从一个vector获取凸包
    convex res(2 * a.size() + 5); //为何？经测试好像只需要a.size()？
    if(flag)
    sort(a.begin(), a.end(),cmpl);
    else
    sort(a.begin(), a.end(),cmpr);
    a.erase(unique(a.begin(), a.end()), a.end());
    int m = 0;
    for (int i = 0; i < a.size(); i++)
    {
        //<=0则不含边界，<0则含边界
        while(m > 1 && sgn(det(res.p[m - 1] - res.p[m - 2], a[i] - res.p[m - 2])) <= 0)
            m--;
        res.p[m++] = a[i];
    }
    int k = m;
    for (int i = a.size() - 2; i >= 0; i--)
    {
        while(m > k && sgn(det(res.p[m - 1] - res.p[m - 2], a[i] - res.p[m - 2])) <= 0)
            m--;
        res.p[m++] = a[i];
    }
    if (m > 1) m--;
    res.p.resize(m);
    res.n = m;
    return res;
}

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i=0; i<n; ++i)
        {
            a[i].in();
        }
        sort(a,a+n);
        scanf("%d", &q);
        printf("Case #%d:\n", cs++);
        for(int i=0; i<q; ++i)
        {
            scanf("%lf", &x.x);
            x.y=0;
            int rnk = lower_bound(a,a+n,x) - a;
            l.clear();
            r.clear();
            l.push_back(x);
            for(int j=rnk-1; j>=0; --j)
            {
                l.push_back(a[j]);
            }
            convex cl =  convexhull(l,1);
            r.push_back(x);
            for(int j=rnk; j<n; ++j)
            {
                r.push_back(a[j]);
            }
            convex cr = convexhull(r,0);
            point ansl, ansr;
            ansl = cl.p[1], ansr = cr.p[1];

            cout<<cl.p[1].x<<" "<<cr.p[1].x<<endl;

            double ans = atan(ansl.y/(x.x-ansl.x))+atan(ansr.y/(ansr.x-x.x));
            printf("%.6f\n", 180-ans*180/pi);
        }
    }
}
