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
#define disc B*B-4*A*C//总判别式（discriminant=B*B-4*A*C）
int sgn(double x);
double pows(double x,double y)//VC++6.0的库函里面，只能给正数开方，不能给负数开奇次方。
{
    double a;
    a=sgn(x)*pow(fabs(x),y);
    return a;
}
int sgn(double x)//符号函数sgn x.x<0时,sgn x=-1;x=0时,sgn x=0;x>0时，sgn x=1.
{
    if(x>0)
        return 1;
    else if(x<0)
        return -1;
    else
        return 0;
}//上述两个函数解决了给负数开奇次方的问题。

double cal(double a,double b ,double c, double d)
{
    double A,B,C;
    A=b*b-3*a*c;
    B=b*c-9*a*d;
    C=c*c-3*b*d;
    double Y1,Y2;
    Y1=A*b+3*a*(-B+sqrt(B*B-4*A*C))/2;
    Y2=A*b+3*a*(-B-sqrt(B*B-4*A*C))/2;
    double x1,x2,x3;
    if(A==0&&B==0)
    {
        x1 = -b/(3*a);
        x2 = -c/b;
        x3 = -3*d/c;
        cout<<"x1="<<-b/(3*a)<<endl;
        cout<<"x2="<<-c/b<<endl;
        cout<<"x3="<<-3*d/c<<endl;
    }
    else if(disc>0)
    {
        x1 = (-b-pows(Y1,1.0/3)-pows(Y2,1.0/3))/(3*a);
        cout<<"x1="<<(-b-pows(Y1,1.0/3)-pows(Y2,1.0/3))/(3*a)<<endl;
        cout<<"x2="<<(-2*b+pows(Y1,1.0/3)-pows(Y2,1.0/3))/(6*a)<<"+("<<(sqrt(3)*(pows(Y1,1.0/3)-pows(Y2,1.0/3)))/(6*a)<<")i"<<endl;
        cout<<"x3="<<(-2*b+pows(Y1,1.0/3)+pows(Y2,1.0/3))/(6*a)<<"+("<<-(sqrt(3)*(pows(Y1,1.0/3)-pows(Y2,1.0/3)))/(6*a)<<")i"<<endl;
    }
    else if(disc!=0)
    {
        double K;
        K=B/A;
        x1 = -b/a+K;
        cout<<"x1="<<-b/a+K<<endl;
        cout<<"x2="<<-K/2<<endl;
        cout<<"x3="<<-K/2<<endl;
    }
    else if(disc<0)
    {
        double air,T;
        T=(2*A*b-3*a*B)/pows(2*A,3.0/2);
        air=acos(T);
        if(A>0&&T<1.0&&T>-1.0)
        {
            x1 = (-b-sqrt(2*A)*cos(air/3))/(3*a);
            cout<<"x1="<<(-b-sqrt(2*A)*cos(air/3))/(3*a)<<endl;
            cout<<"x2="<<(-b-sqrt(A)*(cos(air/3)+pows(3,1.0/3)*sin(air/3)))/(3*a)<<endl;
            cout<<"x3="<<(-b-sqrt(A)*(cos(air/3)-pows(3,1.0/3)*sin(air/3)))/(3*a);
        }
        else
            cout<<"There is an error!";
    }
    else
        cout<<"There is an error!";
    return x1;
}

double aa,bb,cc,dd,ee,ff;

int main()
{
    while(~scanf("%lf%lf%lf%lf%lf%lf", &aa, &bb,&cc,&dd,&ee,&ff))
    {
        double a,b,c,d;
        dd/=2,ee/=2,ff/=2;
        a = 1.0;
        b = -(aa+bb+cc);
        c = aa*bb+bb*cc+cc*aa-dd*dd-ee*ee-ff*ff;
        d = -(aa*bb*cc+2*dd*ee*ff-aa*ee*ee-bb*ff*ff-cc*dd*dd);
        double ans = cal(a,b,c,d);
    }
}
