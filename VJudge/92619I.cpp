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
const double PI = acos(-1.0);
const double EP = 1e-8;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
using namespace std;

struct POINT
{
    double x;
    double y;
    POINT(double a=0, double b=0)
    {
        x=a;    //constructor
        y=b;
    }
};

//两圆交点：
// 两圆已经相交（相切）
void  c2point(POINT p1,double r1,POINT p2,double r2,POINT &rp1,POINT &rp2)
{
    double a,b,r;
    a=p2.x-p1.x;
    b=p2.y-p1.y;
    r=(a*a+b*b+r1*r1-r2*r2)/2;
    if(a==0&&b!=0)
    {
        rp1.y=rp2.y=r/b;
        rp1.x=sqrt(r1*r1-rp1.y*rp1.y);
        rp2.x=-rp1.x;
    }
    else if(a!=0&&b==0)
    {
        rp1.x=rp2.x=r/a;
        rp1.y=sqrt(r1*r1-rp1.x*rp2.x);
        rp2.y=-rp1.y;
    }
    else if(a!=0&&b!=0)
    {
        double delta;
        delta=b*b*r*r-(a*a+b*b)*(r*r-r1*r1*a*a);
        rp1.y=(b*r+sqrt(delta))/(a*a+b*b);
        rp2.y=(b*r-sqrt(delta))/(a*a+b*b);
        rp1.x=(r-b*rp1.y)/a;
        rp2.x=(r-b*rp2.y)/a;
    }

    rp1.x+=p1.x;
    rp1.y+=p1.y;
    rp2.x+=p1.x;
    rp2.y+=p1.y;
}

/* 两圆：
相离： return 1；
外切： return 2；
相交： return 3；
内切： return 4；
内含： return 5；
*/
int CircleRelation(POINT p1, double r1, POINT p2, double r2)
{
    double d = sqrt( (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y) );

    if( fabs(d-r1-r2) < EP ) // 必须保证前两个if先被判定！
        return 2;
    if( fabs(d-fabs(r1-r2)) < EP ) //内切
        return 4;
    if( d > r1+r2 )
        return 1;
    if( d < fabs(r1-r2) )  //内含
        return 5;
    if( fabs(r1-r2) < d && d < r1+r2 )
        return 3;
    return 0; // indicate an error!
}

double c2area(POINT c1,double r1,POINT c2,double r2)              // 两圆面积交
{
    double a1, a2, d, ret;
    d = sqrt((c1.x-c2.x)*(c1.x-c2.x)+(c1.y-c2.y)*(c1.y-c2.y));
    if ( d > r1 + r2 - EP )
        return 0;
    if ( d < r2 - r1 + EP )
        return PI*r1*r1;
    if ( d < r1 - r2 + EP )
        return PI*r2*r2;
    a1 = acos((r1*r1+d*d-r2*r2)/2/r1/d);
    a2 = acos((r2*r2+d*d-r1*r1)/2/r2/d);
    ret = (a1-0.5*sin(2*a1))*r1*r1 + (a2-0.5*sin(2*a2))*r2*r2;
    return ret;
}

int t,cs=0;
double r,R;
POINT a,b;

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lf%lf", &r, &R);
        scanf("%lf%lf%lf%lf", &a.x,&a.y,&b.x,&b.y);
        int BigxBig = CircleRelation(a,R,b,R);
        int BigxSmall = CircleRelation(a,R,b,r);
        int SmallxSmall = CircleRelation(a,r,b,r);
        //cout<<BigxBig<<" "<<BigxSmall<<" "<<SmallxSmall<<endl;
        printf("Case #%d: ", ++cs);
        double BxB,BxS,SxS;
        if(BigxBig<=2)  BxB = 0;
        else BxB = c2area(a,R,b,R);
        if(BigxSmall<=2)  BxS = 0;
        else BxS = c2area(a,r,b,R);
        if(SmallxSmall<=2)  SxS = 0;
        else SxS = c2area(a,r,b,r);
        //cout<<BxB<<" "<<BxS<<" "<<SxS<<endl;
        printf("%.6f\n", BxB-BxS*2+SxS);
    }
}
