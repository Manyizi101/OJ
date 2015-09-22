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

struct node
{
    double x,y;
    node(){}
    node(double xx,double yy)
    {
        x=xx;
        y=yy;
    }
    node operator -(node s)
    {
        return node(x-s.x,y-s.y);
    }
    node operator +(node s)
    {
        return node(x+s.x,y+s.y);
    }
    double operator *(node s)
    {
        return x*s.x+y*s.y;
    }
    double operator ^(node s)
    {
        return x*s.y-y*s.x;
    }
}p[M];
double max(double a,double b)
{
    return a>b?a:b;
}
double min(double a,double b)
{
    return a<b?a:b;
}
double len(node a)
{
    return sqrt(a*a);
}
double dis(node a,node b)//两点之间的距离
{
    return len(b-a);
}
double cross(node a,node b,node c)//叉乘
{
    return (b-a)^(c-a);
}
double dot(node a,node b,node c)//点成
{
    return (b-a)*(c-a);
}
int judge(node a,node b,node c)//判断c是否在ab线段上（前提是c在直线ab上）
{
    if(c.x>=min(a.x,b.x)
       &&c.x<=max(a.x,b.x)
       &&c.y>=min(a.y,b.y)
       &&c.y<=max(a.y,b.y))
        return 1;
    return 0;
}
double area(node b,node c,double r)
{
    node a(0.0,0.0);
    if(dis(b,c)<eps)
        return 0.0;
    double h=fabs(cross(a,b,c))/dis(b,c);
    if(dis(a,b)>r-eps&&dis(a,c)>r-eps)//两个端点都在圆的外面则分为两种情况
    {
        double angle=acos(dot(a,b,c)/dis(a,b)/dis(a,c));
        if(h>r-eps)
        {
            return 0.5*r*r*angle;
        }
        else if(dot(b,a,c)>0&&dot(c,a,b)>0)
        {
            double angle1=2*acos(h/r);
            return 0.5*r*r*fabs(angle-angle1)+0.5*r*r*sin(angle1);
        }
        else
        {
            return 0.5*r*r*angle;
        }
    }
    else if(dis(a,b)<r+eps&&dis(a,c)<r+eps)//两个端点都在圆内的情况
    {
        return 0.5*fabs(cross(a,b,c));
    }
    else//一个端点在圆上一个端点在圆内的情况
    {
        if(dis(a,b)>dis(a,c))//默认b在圆内
        {
            swap(b,c);
        }
        if(fabs(dis(a,b))<eps)//ab距离为0直接返回0
        {
            return 0.0;
        }
        if(dot(b,a,c)<eps)
        {
            double angle1=acos(h/dis(a,b));
            double angle2=acos(h/r)-angle1;
            double angle3=acos(h/dis(a,c))-acos(h/r);
            return 0.5*dis(a,b)*r*sin(angle2)+0.5*r*r*angle3;

        }
        else
        {
            double angle1=acos(h/dis(a,b));
            double angle2=acos(h/r);
            double angle3=acos(h/dis(a,c))-angle2;
            return 0.5*r*dis(a,b)*sin(angle1+angle2)+0.5*r*r*angle3;
        }
    }
}

int n;
double k;

int main()
{
    double x,y,h,x1,y1,R;
    double x1,x2,y1,y2;
    while(~scanf("%d%lf", &n,&k))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf",&p[i].x,&p[i].y);
        }
        p[n]=p[0];
        scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
        node O(x0,y0);
        for(int i=0;i<=n;i++)
            p[i]=p[i]-O;
        O=node(0,0);
        double sum=0;
        for(int i=0;i<n;i++)
        {
            int j=i+1;
            double s=area(p[i],p[j],R);
            if(cross(O,p[i],p[j])>0)
                sum+=s;
            else
                sum-=s;
        }
        printf("%.2lf\n",fabs(sum));
    }
    return 0;
}
