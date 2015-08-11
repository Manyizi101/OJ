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

/*
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
        return sgn(det(b - l.s, l.vec())) * sgn(det(a - l.s, l.vec())) > 0;
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
**/

struct line {
    double sx, sy, ex, ey;
    double k, b, A, B, C;
    int id;
    line(double _sx = 0, double _sy = 0, double _ex = 0, double _ey = 0, int _id = 0) {
        sx = _sx; sy = _sy;
        ex = _ex; ey = _ey;
        id = _id;
        k = (_sy - _ey) / (_sx - _ex);
        b = _sy - _sx * k;
        A = (-k);
        B = 1;
        C = (- _sx) * A - _sy;
    }
};

int n;
vector<line> ans;
line x;

bool cross_Judge(line a , line b) {
    double a11 = a.ex - a.sx;
    double a12 = a.ey - a.sy;
    double a21 = b.sx - a.sx;
    double a22 = b.sy - a.sy;
    double a31 = b.ex - a.sx;
    double a32 = b.ey - a.sy;
    if ((a11 * a22 - a21 * a12) * (a11 * a32 - a31 * a12) < 0)
        return true;
    return false;
}
bool same(line a , line b) {
    if (a.sx == b.sx && a.sy == b.sy && a.ex == b.ex && a.ey == b.ey) return true;
    if (a.sx == b.ex && a.sy == b.ey && a.ex == b.sx && a.ey == b.sy) return true;
    return false;
}
bool cover(line a , line b) {
    if (a.k == b.k && a.b == b.b) {
        if (a.sx < b.sx && a.sx > b.ex) return true;
        if (a.sx > b.sx && a.sx < b.ex) return true;
        if (a.ex < b.sx && a.ex > b.ex) return true;
        if (a.ex > b.sx && a.ex < b.ex) return true;
        if (b.sx < a.sx && b.sx > a.ex) return true;
        if (b.sx > a.sx && b.sx < a.ex) return true;
        if (b.ex < a.sx && b.ex > a.ex) return true;
        if (b.ex > a.sx && b.ex < a.ex) return true;
    }
    return false;
}
bool cross(line a , line b) {
    if (same(a, b)) return true;
    if (cover(a, b)) return true;
    if (min(a.sx, a.ex) > max(b.sx, b.ex)) return false;
    if (min(b.sx, b.ex) > max(a.sx, a.ex)) return false;
    if (min(a.sy, a.ey) > max(b.sy, b.ey)) return false;
    if (min(b.sy, b.ey) > max(a.sy, a.ey)) return false;
    return (cross_Judge(a, b) && cross_Judge(b, a));
}

// int main()
// {
//     while (~scanf("%d", &n) && n)
//     {
//         ans.clear();
//         x.in();
//         x.id = 1;
//         ans.push_back(x);
//         for (int i = 1; i < n; ++i)
//         {
//             x.in();
//             x.id = i + 1;
//             for (unsigned j = 0; j < ans.size(); ++j)
//             {
//                 if (cross(ans[j], x))
//                 {
//                     ans.erase(ans.begin() + j);
//                 }
//             }
//             ans.push_back(x);
//         }
//         printf("Top sticks: ");
//         for (unsigned i = 0; i < ans.size() - 1; ++i)
//         {
//             printf("%d, ", ans[i].id);
//         }
//         printf("%d.\n", ans[ans.size() - 1].id);
//     }
// }

const int maxn = 1e5 + 10;

int v[maxn];

int main(int argc, char const *argv[])
{
    int n;
    while (cin >> n && n)
    {
        queue<line> q;
        for (int i = 0; i < n; ++i)
        {
            double a, b, c, d;
            scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
            line L = line(a, b, c, d, i + 1);
            int len = q.size();
            for (int j = 0; j < len; ++j)
            {
                if (!cross(L, q.front()))
                    q.push(q.front());
                q.pop();
            }
            q.push(L);
        }
        printf("Top sticks: ");
        int cnt = 0;
        while (!q.empty()) {
            v[cnt++] = q.front().id;
            q.pop();
        }
        int i ;
        for (i = 0 ; i < cnt - 1 ; i++)
            printf("%d, ", v[i]);
        printf("%d.\n", v[i]);
    }
    return 0;
}


























































