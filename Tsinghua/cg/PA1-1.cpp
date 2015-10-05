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
using namespace std;

const double INF = 1E200;
const double eps = 1e-10;
const double pi = acos(-1.0);
const int maxp = 1010;
const int maxn = 1010;
int n;

inline double sqr(double x) {
    return x * x;
}

//返回坐标的正负
int sgn(double x) {
    if (fabs(x) < eps) return 0;
    return x > eps ? 1 : -1;
}

struct Point {
    //内部变量
    double x, y;

    //构造函数
    Point() { }

    Point(double _x, double _y) {
        x = _x;
        y = _y;
    }


    //输入输出函数
    int in() {
        return scanf("%lf%lf", &x, &y);
    }

    void out() {
        printf("%.2f %.2f\n", x, y);
    }


    //重载运算符
    Point operator-(const Point &b) const {
        return Point(x - b.x, y - b.y);
    }

    Point operator+(const Point &b) const {
        return Point(x + b.x, y + b.y);
    }

    Point operator/(double k) const {
        return Point(x / k, y / k);
    }

    Point operator*(double k) const {
        return Point(x * k, y * k);
    }

    //点积，内积
    double operator*(const Point &b) const {
        return x * b.x + y * b.y;
    }

    //叉积，外积
    double operator^(const Point &b) const {
        return x * b.y - y * b.x;
    }

    //判断是否重合
    bool operator==(Point a) const {
        return sgn(a.x - x) == 0 && sgn(a.y - y) == 0;
    }

    //先判断X在判断Y，必要时需要自己重载
    bool operator<(Point a) const {
        return sgn(x - a.x) == 0 ? sgn(y - a.y) < 0 : x < a.x;
    }

    //常用函数
    //绕点p逆时针旋转angle角度，angle以弧度形式输入
    Point rotate(Point p, double angle) {
        Point v = *this - p;
        double c = cos(angle), s = sin(angle);
        return Point(p.x + v.x * c - v.y * s, p.y + v.x * s + v.y * c);
    }

    //到原点的距离
    double len() {
        //hypot(x,y)    返回sqrt(x*x+y*y)
        return hypot(x, y);
    }

    //到原点距离的平方
    double len2() {
        return x * x + y * y;
    }

    //返回到点p的距离
    double dis(Point p) {
        return hypot(x - p.x, y - p.y);
    }

    Point rotleft() {
        return Point(-y, x);
    }

    Point rotright() {
        return Point(y, -x);
    }

    Point trunc(double x) {
        return (*this) / x;
    }
};

//直线
struct Line {
    //内部变量
    Point s, e;

    //构造函数
    Line() { }

    //两点式
    Line(Point _s, Point _e) {
        s = _s;
        e = _e;
    }

    //点斜式
    Line(Point p, double angle) {
        s = p;
        if (sgn(angle - pi / 2) == 0) {
            e = s + Point(0, 1);
        } else {
            e = s + Point(1, tan(angle));
        }
    }

    //一般方程
    Line(double a, double b, double c) {
        if (sgn(a) == 0) {
            s = Point(0, -c / b);
            e = Point(1, -c / b);
        } else if (sgn(b) == 0) {
            s = Point(-c / a, 0);
            e = Point(-c / a, 1);
        } else {
            s = Point(0, -c / b);
            e = Point(1, (-c - a) / b);
        }
    }

    //输入输出函数
    void in() {
        s.in();
        e.in();
    }

    //重载运算符
    bool operator==(Line v) const {
        return (s == v.s) && (e == v.e);
    }

    //常用函数
    double len() {
        return s.dis(e);
    }

    //返回直线倾斜角，0<=angle<pi
    double angle() {
        double k = atan2(e.y - s.y, e.x - s.x);
        if (sgn(k) < 0) k += pi;
        if (sgn(k - pi) == 0) k += pi;
        return k;
    }

    Point lineprog(Point p) {
        return s + ((e - s) * ((e - s) * (p - s)) / (e - s).len2());
    }

    //几何关系
    //点与直线
    /*
     * 判断点与直线的关系
     * -1   在直线的逆时针方向
     * 0    在直线上
     * 1    在直线的顺时针方向
     */
    int ispointonline(Point p) {
        int c = sgn((p - s) ^ (e - s));
        if (c < 0) return -1;
        else if (c == 0) return 0;
        else return 1;
    }

    //点到直线距离
    double dispointtoline(Point p) {
        return fabs((p - s) ^ (e - s)) / len();
    }

    //直线与直线
    //相交返回true，平行返回false
    bool islinexline(Line v) {
        return sgn((e - s) ^ (v.e - v.s)) != 0;
    }

    Point linexline(Line v) {
        double a1 = (v.e - v.s) ^(s - v.s);
        double a2 = (v.e - v.s) ^(e - v.s);
        return Point((s.x * a2 - e.x * a1) / (a2 - a1), (s.y * a2 - e.y * a1) / (a2 - a1));
    }
};

//线段
struct Lineseg : public Line {
    //构造函数
    Lineseg() { }

    Lineseg(Point _s, Point _e) {
        s = _s, e = _e;
    }

    //几何关系
    //点与线段
    //判断点是否在线段上
    int ispointonlineseg(Point p) {
        return sgn((p - s) ^ (e - s)) == 0 && sgn((p - s) * (p - e)) <= 0;
    }

    double dispointtolineseg(Point p) {
        if (sgn((p - e) * (s - e)) < 0 || sgn((p - s) * (e - s)) < 0) {
            return min(p.dis(s), p.dis(e));
        }
        return dispointtoline(p);
    }

    //直线与线段
    /*
     * 判断直线与线段的关系
     * 2 规范相交
     * 1 非规范相交
     * 0 不相交
     */
    int islinexlineseg(Line v) {
        int d1 = sgn((e - s) ^ (v.s - s));
        int d2 = sgn((e - s) ^ (v.e - s));
        if ((d1 ^ d2) == -2)return 2;
        return (d1 == 0 || d2 == 0);
    }

    //线段与线段
    /*
    * 判断线段与线段的关系
    * 2 规范相交
    * 1 非规范相交
    * 0 不相交
    */
    int islinesegxlineseg(Lineseg v) {
        int d1 = sgn((e - s) ^ (v.s - s));
        int d2 = sgn((e - s) ^ (v.e - s));
        int d3 = sgn((v.e - v.s) ^ (s - v.s));
        int d4 = sgn((v.e - v.s) ^ (e - v.s));
        if ((d1 ^ d2) == -2 && (d3 ^ d4) == -2)return 2;
        return (d1 == 0 && sgn((v.s - s) * (v.s - e)) <= 0 ||
                d2 == 0 && sgn((v.e - s) * (v.e - e)) <= 0 ||
                d3 == 0 && sgn((s - v.s) * (s - v.e)) <= 0 ||
                d4 == 0 && sgn((e - v.s) * (e - v.e)) <= 0);
    }

    //返回线段与线段的交点，只有两线段规范相交时才有意义
    Point linesegxlineseg(Lineseg v) {
        double a1 = (v.e - v.s) ^(s - v.s);
        double a2 = (v.e - v.s) ^(e - v.s);
        return Point((s.x * a2 - e.x * a1) / (a2 - a1), (s.y * a2 - e.y * a1) / (a2 - a1));
    }
};

struct Circle {
    //参数
    Point p;
    double r;

    //构造函数
    Circle() { }

    Circle(Point _p, double _r) {
        p = _p;
        r = _r;
    }

    Circle(double _x, double _y, double _r) {
        p = Point(_x, _y);
        r = _r;
    }

    //三角形的外接圆
    Circle(Point a, Point b, Point c) {
        p = Line((a + b) / 2, ((a + b) / 2) + ((b - a).rotleft())).linexline(
                Line((c + b) / 2, ((c + b) / 2) + ((b - c).rotleft())));
        r = p.dis(a);
    }

    //三角形的内切圆
    //多传一个无用的bool参数以区分构造函数
    Circle(Point a, Point b, Point c, bool t) {
        Line u, v;
        double m = atan2(b.y - a.y, b.x - a.x), n = atan2(c.y - a.y, c.x - a.x);
        u.s = a;
        u.e = u.s + (Point(cos((n + m) / 2), sin((n + m) / 2)));
        v.s = b;
        m = atan2(a.y - b.y, a.x - b.x), n = atan2(c.y - b.y, c.x - b.x);
        v.e = v.s + (Point(cos((n + m) / 2), sin((n + m) / 2)));
        p = u.linexline(v);
        r = Line(a, b).dispointtoline(p);
    }

    //输入输出
    void in() {
        p.in();
        scanf("%lf", &r);
    }

    void out() {
        printf("%.2f %.2f %.2f\n", p.x, p.y, r);
    }

    //重载运算符
    bool operator==(Circle v) {
        return ((p == v.p) && sgn(r - v.r) == 0);
    }

    bool operator<(Circle v) {
        return ((p < v.p) || (p == v.p) && sgn(r - v.r) < 0);
    }

    //常用函数
    //返回圆的面积
    double area() {
        return pi * sqr(r);
    }

    //返回圆的周长
    double c() {
        return 2 * pi * r;
    }

    //各种圆
    //过a,b两点 半径为r的两个圆
    int getcircle(Point a, Point b, double r, Circle &c1, Circle &c2) {
        Circle x(a, r), y(b, r);
        int t = x.circlexcircle(y, c1.p, c2.p);
        if (!t)return 0;
        c1.r = c2.r = r;
        return t;
    }

    //与直线u相切 过点q 半径r1的圆
    int getcircle(Line u, Point q, double r1, Circle &c1, Circle &c2) {
        double dis = u.dispointtoline(q);
        if (sgn(dis - r1 * 2) > 0)return 0;
        if (sgn(dis) == 0) {
            c1.p = q + ((u.e - u.s).rotleft().trunc(r1));
            c2.p = q + ((u.e - u.s).rotright().trunc(r1));
            c1.r = c2.r = r1;
            return 2;
        }
        Line u1 = Line(u.s + ((u.e - u.s).rotleft().trunc(r1)), u.s + ((u.e - u.s).rotleft().trunc(r1)));
        Line u2 = Line(u.s + ((u.e - u.s).rotright().trunc(r1)), u.s + ((u.e - u.s).rotright().trunc(r1)));
        Circle cc = Circle(q, r1);
        Point p1, p2;
        if (!cc.linexcircle(u1, p1, p2))cc.linexcircle(u2, p1, p2);
        c1 = Circle(p1, r1);
        if (p1 == p2) {
            c2 = c1;
            return 1;
        }
        c2 = Circle(p2, r1);
        return 2;
    }

    //同时与直线u,v相切 半径r1的圆
    int getcircle(Line u, Line v, double r1, Circle &c1, Circle &c2, Circle &c3, Circle &c4) {
        if (!u.islinexline(v))return 0;
        Line u1 = Line(u.s + ((u.e + u.s).rotleft().trunc(r1)), u.e + ((u.e - u.s).rotleft().trunc(r1)));
        Line u2 = Line(u.s + ((u.e - u.s).rotright().trunc(r1)), u.e + ((u.e - u.s).rotright().trunc(r1)));
        Line v1 = Line(v.s + ((v.e + v.s).rotleft().trunc(r1)), v.e + ((v.e - v.s).rotleft().trunc(r1)));
        Line v2 = Line(v.s + ((v.e - v.s).rotright().trunc(r1)), v.e + ((v.e + v.s).rotright().trunc(r1)));
        c1.r = c2.r = c3.r = c4.r = r1;
        c1.p = u1.linexline(v1);
        c2.p = u1.linexline(v2);
        c3.p = u2.linexline(v1);
        c4.p = u2.linexline(v2);
        return 4;
    }

    //同时与不相交圆cx,cy相切 半径为r1的圆
    int getcircle(Circle cx, Circle cy, double r1, Circle &c1, Circle &c2) {
        Circle x(cx.p, r1 + cx.r), y(cy.p, r1 + cy.r);
        int t = x.circlexcircle(y, c1.p, c2.p);
        if (!t)return 0;
        c1.r = c2.r = r1;
        return t;
    }

    //与圆相交的面积
    double areacircle(Circle v) {
        int rel = iscirclexcircle(v);
        if (rel >= 4)return 0.0;
        if (rel <= 2)return min(area(), v.area());
        double d = p.dis(v.p);
        double hf = (r + v.r + d) / 2.0;
        double ss = 2 * sqrt(hf * (hf - r) * (hf - v.r) * (hf - d));
        double a1 = acos((r * r + d * d - v.r * v.r) / (2.0 * r * d));
        a1 = a1 * r * r;
        double a2 = acos((v.r * v.r + d * d - r * r) / (2.0 * v.r * d));
        a2 = a2 * v.r * v.r;
        return a1 + a2 - ss;
    }

    //几何关系
    //点与圆
    /*
     * 返回点与圆的关系
     * 0   园外
     * 1    圆上
     * 2    圆内
     */
    int ispointoncircle(Point b) {
        double dst = b.dis(p);
        if (sgn(dst - r) < 0) return 2;
        else if (sgn(dst - r) == 0) return 1;
        else return 0;
    }

    //直线与圆
    /*
     * 返回直线与圆的关系
     * 0   相离
     * 1   相切
     * 2   相交
     */
    int islinexcircle(Line v) {
        double dst = v.ispointonline(p);
        if (sgn(dst - r) < 0)return 2;
        if (sgn(dst - r) == 0)return 1;
        return 0;
    }

    int linexcircle(Line v, Point &p1, Point &p2) {
        if (!(*this).islinexcircle(v)) return 0;
        Point a = v.lineprog(p);
        double d = v.dispointtoline(p);
        d = sqrt(r * r - d * d);
        if (sgn(d) == 0) {
            p1 = a;
            p2 = a;
            return 1;
        }
        p1 = a - (v.e - v.s).trunc(d);
        p2 = a + (v.e - v.s).trunc(d);
        return 2;
    }

    //过一点做圆的切线（需要首先判断点与圆的关系）
    int tangentline(Point q, Line &u, Line &v) {
        int x = ispointoncircle(q);
        if (x == 2)return 0;
        if (x == 1) {
            u = Line(q, q + ((q - p).rotleft()));
            v = u;
            return 1;
        }
        double d = p.dis(q);
        double l = sqr(r) / d;
        double h = sqrt(sqr(r) - sqr(l));
        u = Line(q, p + ((q - p).trunc(l) + ((q - p).rotleft().trunc(h))));
        v = Line(q, p + ((q - p).trunc(l) + ((q - p).rotright().trunc(h))));
        return 2;
    }

    //线段与圆
    /*
     * 返回线段与圆的关系
     * 0   相离
     * 1   相切（或有一个端点在圆上）
     * 2   相交（有一部分线段在园内）
     */
    int islinesegxcircle(Lineseg v) {
        double dst = v.dispointtolineseg(p);
        if (sgn(dst - r) < 0) return 2;
        if (sgn(dst - r) == 0) return 1;
        return 0;
    }

    int linesegxcircle(Lineseg v, Point p[]) { }

    //圆与圆
    //判断圆与圆的关系
    /*
     * 5 相离
     * 4 外切
     * 3 相交
     * 2 内切
     * 1 内含
     */
    int iscirclexcircle(Circle v) {
        double d = p.dis(v.p);
        if (sgn(d - r - v.r) > 0)return 5;
        if (sgn(d - r - v.r) == 0)return 4;
        double l = fabs(r - v.r);
        if (sgn(d - r - v.r) < 0 && sgn(d - l) > 0)return 3;
        if (sgn(d - l) == 0)return 2;
        if (sgn(d - l) < 0)return 1;
    }

    int circlexcircle(Circle v, Point &q1, Point &q2) {
        int rel = iscirclexcircle(v);
        if (rel == 1 || rel == 5)return 0;
        double d = p.dis(v.p);
        double l = (d + (sqr(r) - sqr(v.r)) / d) / 2;
        double h = sqrt(sqr(r) - sqr(l));
        q1 = p + ((v.p - p).trunc(l) + ((v.p - p).rotleft()).trunc(h));
        q2 = p + ((v.p - p).trunc(l) + ((v.p - p).rotright()).trunc(h));
        if (rel == 2 || rel == 4) {
            return 1;
        }
        return 2;
    }
};

struct Polygon {
    //变量
    int n;
    Point p[maxp];
    Lineseg l[maxp];

    //构造函数
    Polygon() { }

    Polygon(int _n, Point _p[]) {
        n = _n;
        for (int i = 0; i < _n; ++i) p[i] = _p[i];
    }

    //输入输出
    void in() {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            p[i].in();
        }
    }

    //常用函数
    //加点
    void add(Point q) {
        p[n++] = q;
    }

    //生成边
    void getline() {
        for (int i = 0; i < n; ++i) {
            l[i] = Lineseg(p[i], p[(i + 1) % n]);
        }
    }

    //多边形周长
    double c() {
        double sum = 0.0;
        for (int i = 0; i < n; ++i) {
            sum += l[i].len();
        }
    }

    //多边形面积
    double area() {
        double sum = 0.0;

    }

    //获取多边形的方向
    bool getdir() {
        double sum = 0;
        int i;
        for (i = 0; i < n; i++) {
            sum += p[i] ^ (p[(i + 1) % n]);
        }
        if (sgn(sum) > 0)return 1;
        return 0;
    }

    //多边形重心
    Point masscenter() {
        Point ans(0.0, 0.0);
        if (sgn(area()) == 0) return ans;
        for (int i = 0; i < n; ++i) {
            ans = ans + (p[i] + p[(i + 1) % n]) * (p[i] ^ p[(i + 1) % n]);
        }
        return ans / area() / 6;
    }

    //多边形边界上格点数量
    int borderpointnum() {
        int num;
        for (int i = 0; i < n; ++i) {
            int a = fabs(p[(i + 1) % n].x - p[i].x);
            int b = fabs(p[(i + 1) % n].y - p[i].y);
            num += __gcd(a, b);
        }
    }

    //多边形内格点数量
    int insidepointnum() {
        return int(area()) + 1 - borderpointnum() / 2;
    }

    //几何关系
    //点与多边形
    /*
     * 点与多边形的关系
     * 3 点上
     * 2 边上
     * 1 内部
     * 0 外部
     */
    int ispointonpolygon(Point q) {
        int i, j;
        for (i = 0; i < n; i++) {
            if (p[i] == q)return 3;
        }
        getline();
        for (i = 0; i < n; i++) {
            if (l[i].ispointonlineseg(q))return 2;
        }
        int cnt = 0;
        for (i = 0; i < n; i++) {
            j = (i + 1) % n;
            int k = sgn((q-p[j])^(p[i]-p[j]));
            int u = sgn(p[i].y - q.y);
            int v = sgn(p[j].y - q.y);
            if (k > 0 && u < 0 && v >= 0)cnt++;
            if (k < 0 && v < 0 && u >= 0)cnt--;
        }
        return cnt != 0;
    }

    //直线与多边形
    /*
     * 直线与多边形的关系
     * 1 在多边形内长度为正
     * 2 相交或与边平行
     * 0 无任何交点
     */
    //线段与多边形
    int islinesegxpolygon(Lineseg v) { }

void getconvex(Polygon &convex) {
        int i, j, k;
        sort(p, p + n);
        convex.n = n;
        for (i = 0; i < min(n, 2); i++) {
            convex.p[i] = p[i];
        }
        if (n <= 2)return;
        int &top = convex.n;
        top = 1;
        for (i = 2; i < n; i++) {
            while (top && ((convex.p[top]-p[i])^(convex.p[top - 1]-p[i])) < 0)
                top--;
            convex.p[++top] = p[i];
        }
        int temp = top;
        convex.p[++top] = p[n - 2];
        for (i = n - 3; i >= 0; i--) {
            while (top != temp && ((convex.p[top]-p[i])^(convex.p[top - 1]-p[i])) < 0)
                top--;
            convex.p[++top] = p[i];
        }
    }

};

struct Convex : public Polygon {
    //变量

    //构造函数
    Convex() { }



    //输入输出

    //常用函数
    //直线u切割凸多边形左侧，注意直线方向
    void convexcut(Line u, Convex &po) {
        int i, j, k;
        int &top = po.n;
        top = 0;
        for (i = 0; i < n; i++) {
            int d1 = sgn((p[i] - u.s) ^ (u.e - u.s));
            int d2 = sgn((p[(i + 1) % n] - u.s) ^ (u.e - u.s));
            if (d1 >= 0)po.p[top++] = p[i];
            if (d1 * d2 < 0)po.p[top++] = u.linexline(Line(p[i], p[(i + 1) % n]));
        }
    }




};

Polygon co;
Polygon xx;

int main() {
    while(~scanf("%d", &n)) {
        for(int i=0; i<n; ++i) {
            co.p[i].in();
        }
        co.n=n;
        co.getconvex(xx);
        cout<<xx.n<<endl;
    }

}
