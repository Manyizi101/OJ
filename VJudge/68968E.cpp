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

struct Point
{
    double x,y;
};

inline int sgn(const double &x)
{
    return x < -eps ? -1 : x > eps;
}

double dot (double x1,double y1, double x2,double y2)
{
    return x1*y2-x2*y1;
}

double cross(Point a ,Point b,Point c)
{
    return dot(b.x-a.x,b.y-a.y,c.x-a.x,c.y-a.y);
}

double lineseg(Point a, Point b, Point c, Point d)
{
    return (sgn(cross(a,b,c))^sgn(cross(a,b,d))==-2)&&(sgn(cross(c,d,a))^sgn(cross(c,d,b))==-2);
}

double mydist(Point a, Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double g[200][200];
int s,t;
int n;
Point line[200][2];
Point pts[200];

int main()
{
    double x,y1,y2,y3,y4;
    wile(cin>>n)
    {
        if(n==-1)   break;
        s=0,t=4*n+1;
        pts[0].x=0;
        pts[0].y=5;
        pts[t].x=10;
        pts[t].y=5;

        for(int i=0;i<n;++i)
        {
            cin>>x>>y1>>y2>>y3>>y4;

            line[i*3][0].x=x;
            line[i*3][0].y=0;
            line[i*3][1].x=x;
            line[i*3][1].y=y1;
        }
    }
    return 0;
}









