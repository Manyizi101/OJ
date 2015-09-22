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
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
using namespace std;

#define sqr(v) ((v)*(v))

const double eps = 1e-6;

double my_sqrt(double d) { return sqrt(max(d, 0.0)); }
double my_acos(double d) { return acos(d > 1 ? 1 : d < -1 ? -1 : d); }

int sig(double d){
    return (d > eps) - (d < -eps);
}

struct Point{
    double x, y;
    Point() {}
    Point(double x, double y) : x(x), y(y) {}
    Point resize(double d){
        d /= my_sqrt(x*x + y*y);
        return Point(x*d, y*d);
    }
    Point left90(){
        return Point(-y, x);
    }
    Point operator - (const Point & o) const{
        return Point(this -> x - o.x, this -> y - o.y);
    }
    Point operator + (const Point & o) const{
        return Point(this -> x + o.x, this -> y + o.y);
    }
    Point operator * (double d) const{
        return Point(x * d, y * d);
    }
};

double cross(Point o, Point a, Point b){
    return (a.x - o.x)*(b.y - o.y) - (b.x - o.x)*(a.y - o.y);
}

double dot(Point o, Point a, Point b){
    return (a.x - o.x)*(b.x - o.x) + (a.y - o.y)*(b.y - o.y);
}

double dis(Point a, Point b){
    return my_sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

double btw(Point o, Point a, Point b){
    return sig(dot(o, a, b));
}

struct Circle{
    Point center;
    double radis;
};

double pointToLine(Point o, Point a, Point b, Point & res){
    double d = dis(a, b);
    double s = cross(a, b, o) / d;
    res = o + (a- b).left90()*(s/d);
    return fabs(s);
}

int intersect(Point a, Point b, Circle c, Point &p1, Point &p2){
    Point p;
    double d = pointToLine(c.center, a, b, p);
    int v = sig(c.radis - d);
    if(v != -1){
        Point vec = (b - a).resize(my_sqrt(sqr(c.radis) - sqr(d)));
        p1 = p + vec;
        p2 = p - vec;
    }
    return v;
}

//圆与三角形的相交面积
double intersectArea(Circle c, Point a, Point b){
    if(sig(cross(c.center, a, b)) == 0) return 0.0;

    Point o = c.center, p[5];
    double r = c.radis;
    int len = 0;
    p[len++] = a;
    if(intersect(a, b, c, p[1], p[2]) == 1){
        if(btw(p[1], a, b) < 0) p[len++] = p[1];
        if(btw(p[2], a, b) < 0) p[len++] = p[2];
    }
    p[len++] = b;
    if(len == 4 && btw(p[1], p[0], p[2]) > 0) swap(p[1], p[2]);

    double res = 0;
    for(int i = 0; i < len-1; i++){
        if(sig(dis(o, p[i]) - r) > 0 || sig(dis(o, p[i+1]) - r) > 0){
            double theta = my_acos(dot(o, p[i], p[i+1])/dis(o, p[i])/dis(o, p[i+1]));
            res += theta * r * r / 2.0;
        }else{
            res += fabs(cross(o, p[i], p[i+1])/2.0);
        }
    }
    if(sig(cross(o, a, b)) < 0) res = - res;
    return res;
}

double intersectArea(Circle c, Point *ps, int n){
    ps[n] = ps[0];
    double res = 0;
    for(int i = 0; i < n; i++){
        res += intersectArea(c, ps[i], ps[i+1]);
    }
    return fabs(res);
}

const int maxn = 510;

int n;
double k;
Point p[maxn];
int cs = 0;
int main()
{
    double x1,x2,y1,y2;
    while(~scanf("%d%lf", &n,&k))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf",&p[i].x,&p[i].y);
        }
        scanf("%lf%lf%lf%lf", &x1,&y1,&x2,&y2);
        double a = 1-k*k;
        double c = (2*x1*k*k-2*x2)/a;
        double d = (2*y1*k*k-2*y2)/a;
        double e = (x2*x2-k*k*x1*x1+y2*y2-k*k*y1*y1)/a;
        double xx = -c/2;
        double yy = -d/2;
        double r = sqrt(-e+c*c/4+d*d/4);
        Circle C;
        C.center.x = xx;
        C.center.y = yy;
        C.radis = r;
        printf("Case %d: ", ++cs);
        printf("%.10f\n", intersectArea(C,p,n));
    }
    return 0;
}
