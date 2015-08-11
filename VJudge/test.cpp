/********************* Template ************************/
#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

#define EPS         1e-8
#define MAXN        (int)1e5+5
#define MOD         (int)1e9+7
#define PI          acos(-1.0)
#define INF         (1<<30)
#define max(a,b)    ((a) > (b) ? (a) : (b))
#define min(a,b)    ((a) < (b) ? (a) : (b))
#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define BUG         cout<<"BUG! "<<endl;
#define L(t)        (t << 1)
#define R(t)        (t << 1 | 1)
#define Mid(a,b)    ((a + b) >> 1)
#define lowbit(a)   (a & -a)
#define FIN         freopen("in.txt","r",stdin)

// typedef long long LL;
// typedef unsigned long long ULL;
// typedef __int64 LL;
// typedef unisigned __int64 ULL;
// int gcd(int a,int b){ return b?gcd(b,a%b):a; }
// int lcm(int a,int b){ return a*b/gcd(a,b); }

/*********************   F   ************************/
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
struct point {
    double x, y;
    point(double _x, double _y) {
        x = _x; y = _y;
    }
};
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
int v[MAXN];
int main()
{
    //FIN;
    int n ;
    while (cin >> n && n) {
        queue<line> q;
        for (int i = 0 ; i < n ; i++) {
            double a, b, c, d;
            scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
            line L = line(a, b, c, d, i + 1);
            int len = q.size();
            for (int j = 0 ; j < len; j++) {
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