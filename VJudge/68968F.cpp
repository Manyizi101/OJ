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

//���������ƽ��
inline double sqr(const double &x)
{
    return x * x;
}
//�������������
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
    //���ص㵽ԭ��ľ���
    double norm()
    {
        return sqrt(sqr(x) + sqr(y));
    }
    //��������������
    friend double det(const point &a, const point &b)
    {
        return a.x * b.y - a.y * b.x;
    }
    //������������ڻ�
    friend double dot(const point &a, const point &b)
    {
        return a.x * b.x + a.y * b.y;
    }
    //����������֮���߶εĳ���
    friend double dist(const point &a, const point &b)
    {
        return (a - b).norm();
    }
    //�������㹹�ɵ�ֱ�ߵ�����
    double arg()
    {
        return atan2(y, x);
    }
    //��ʱ����תangle����
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
        //���Ĭ�ϲ�����λС����ע���޸�
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
    //����ֱ����(����ж�ƽ�У��������ж�ֱ���غ�)
    bool ispointonline(const point &p) const
    {
        return sgn(det(p - s, t - s)) == 0;
    }
    //�����߶���
    bool ispointonseg(const point &p) const
    {
        return ispointonline(p) && sgn(dot(p - s, p - t)) <= 0;
    }
    //�����߶��ϲ����˵�
    bool ispointonsegex(const point &p)
    {
        return ispointonline(p) && sgn(dot(p - s, p - t)) < 0;
    }
    //�㵽ֱ�ߵĴ���
    point pointprojline(const point &p)
    {
        return s + vec() * ((dot(p - s, vec()) / norm()) / (norm()));
    }
    //�㵽ֱ�ߵľ���
    double pointdistline(const point &p)
    {
        return fabs(det(p - s, vec()) / norm());
    }
    //�㵽�߶εľ���
    double pointdistseg(const point &p)
    {
        if (sgn(dot(p - s, t - s)) < 0) return (p - s).norm();
        if (sgn(dot(p - t, s - t)) < 0) return (p - t).norm();
        return pointdistline(p);
    }
    //�ж���ֱ���Ƿ�ƽ��
    friend bool parallel(const line &l1, const line &l2)
    {
        return !sgn(det(l1.vec(), l2.vec()));
    }
    //�ж��������Ƿ���ֱ�ߵ�ͬһ��
    friend bool sameside(const line &l, const point &a, const point &b)
    {
        return sgn(det(b - l.s, l.vec())) * sgn(det(a - l.s, l.vec())) >= 0;
    }
    //��ֱ�ߵĽ���
    friend point linexline(const line l1, const line l2) //�������������ζ�Ӧ�߳ɱ���
    {
        double s1 = det(l1.s - l2.s, l2.vec());
        double s2 = det(l1.t - l2.s, l2.vec());
        return (l1.t * s1 - l1.s * s2) / (s1 - s2);
    }
    //�ж��߶ν�
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
    //ֱ���ط��߷����ƶ�d����
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
