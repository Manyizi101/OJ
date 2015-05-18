/********************************************************
A   Accepted    2391 KB 15 ms   Visual Studio C++ 2010  1439 B  2013-07-28 09:57:10

���⣺
    ����һ�� N �����͹�����
    �ж� M �����Ƿ������� K ������͹������ڲ���߽�
********************************************************/

#include<stdio.h>
#include<math.h>
#include<iostream>
    using namespace std;

const int maxn = 100000+10;
struct Point{
    double x,y;
    Point() {}
    Point(double _x, double _y)
    {
        x = _x;
        y = _y;
    }

    Point operator - (const Point & B) const
    {
        return Point(x-B.x, y-B.y);
    }
}p[maxn];

const double eps = 1e-10;
int dcmp(double x)
{
    if(fabs(x) < 0) return 0;
    else return x < 0 ? -1 : 1;
}

double Cross(Point A, Point B)
{
    return A.x*B.y - A.y*B.x;
}

/** ��Point �Ƿ����� n �������͹������ڡ����߽硿*/
bool isPointInConvex(Point *p, int n, Point point)
{
    int flag = 0;
    //p[n] = p[0];
    int now = dcmp(Cross(p[0]-point, p[1]-point));
    for(int i = 0; i < n; i++)
    {
        int next = dcmp(Cross(p[i]-point, p[i+1]-point));
        if(next)
        {
            if(flag)
            {    if(flag!=next)
                    return 0;
            }
            else
                flag=next;
            
        }
    
    }
    return 1;
}
int xx[600],yy[600],zz[600];
int main()
{
    int n,m,k;
    int cs=1;
    while(scanf("%d", &n) &&n!=0)
    {
        int Max=0;
        for(int i = 0; i < n; i++)
        {
            cin>>xx[i]>>yy[i]>>zz[i];
            Max=max(Max,zz[i]);
          //  scanf("%lf%lf", &p[i].x, &p[i].y);
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(zz[i]==Max)
            {
                p[cnt].x=1.0*xx[i];
                p[cnt++].y=1.0*yy[i];
            }
        }
        Point point;
        printf("Case #%d: ",cs++);
        if(cnt<=3)
        {
            for(int i=0;i<n;i++)
            {
                if(zz[i]==Max)
                    cout<<1;
                else
                    cout<<0;
            }
            cout<<endl;
            continue;
        }

        for(int i=0;i<n;i++)
        {
            if(zz[i]!=Max)
            {
                cout<<0;
                continue;
            }
            point.x=1.0*xx[i],point.y=1.0*yy[i];
            if (isPointInConvex(p,cnt,point))
                cout<<0; 
            else
                cout<<1;
        }

        cout<<endl;
    }
    return 0;
}

