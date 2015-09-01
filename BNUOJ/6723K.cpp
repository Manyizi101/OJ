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
using namespace std;

typedef long long int ll;
const double pi = acos(-1.0);
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
using namespace std;
const double p=sqrt(3.0);

double aa,bb,cc,dd,ee,ff;
double A,B,C,a,b,c,d;

void gao(double a, double b, double c,double d)
{
    double ans;
    A=b*b-3*a*c;
    B=b*c-9*a*d;
    C=c*c-3*b*d;
    double q=B*B-4*A*C;
    if(fabs(A-B)<eps&&fabs(A)<eps)
    {
        printf("%.8lf\n",sqrt(fabs(-c/b)));
        return;
    }
    if(fabs(B*B-4*A*C)<eps)
    {
        double k=B/A;
        ans=min(fabs(-b/a+k),fabs(-k/2));
        printf("%.8f\n",sqrt(ans));
        return;
    }
    if(q>0)
    {
        double x=A*b+3*a*((-B+sqrt(q))/2);
        double y=A*b+3*a*((-B-sqrt(q))/2);
        double t1= x>0?pow(x,1.0/3):-(pow(fabs(x),1.0/3));
        double t2= y>0?pow(y,1.0/3):-(pow(fabs(y),1.0/3));
        ans=(-b-t1-t2)/(3*a);
        printf("%.8f\n",sqrt(fabs(ans)));
        return;
    }
    else
    {
        double t=acos((2*A*b-3*a*B)/(2*sqrt(A*A*A)))/3;
        double x1,x2,x3;
        x1 = fabs((-b-2*sqrt(A)*cos(t))/(3*a));
        x2 = fabs(((-b)+sqrt(A)*(cos(t)+p*sin(t)))/(3*a));
        x3 = fabs(((-b)+sqrt(A)*(cos(t)-p*sin(t)))/(3*a));
        ans = min(x1,min(x2,x3));
        printf("%.8f\n",sqrt(ans));
        return;
    }
}

int main()
{
    while(~scanf("%lf%lf%lf%lf%lf%lf",&aa,&bb,&cc,&dd,&ee,&ff))
    {
        a=4*aa*bb*cc+dd*ee*ff-bb*ee*ee-aa*dd*dd-ff*ff*cc;
        b=4*aa*bb+4*bb*cc+4*aa*cc-ee*ee-ff*ff-dd*dd;
        c=4*aa+4*bb+4*cc;
        d=4.0;
        gao(a,b,c,d);
    }
    return 0;
}
