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
#define debug "output for debug\n"
#define pi (acos(-1.0))
#define eps (1e-4)
#define inf (1<<28)
#define ll long long int
using namespace std;

double a,b,c,r,q,s;
double A,B,C,angel,ans,n;

struct node
{
    double x,y;
} piller[3];

double dis(node a, node b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double fgcd(double a, double b)
{
    if(fabs(b-0)<=eps) return a;
    if(fabs(a-0)<=eps) return b;
    return fgcd(b,fmod(a,b));
}

void init()
{
    memset(piller,0,sizeof(piller));
    for(int i=0; i<3; i++)
    {
        scanf("%lf%lf", &piller[i].x,&piller[i].y);
    }
    a=dis(piller[0],piller[1]);
    b=dis(piller[1],piller[2]);
    c=dis(piller[0],piller[2]);
    q=(a+b+c)/2;
    s=sqrt(q*(q-a)*(q-b)*(q-c));
    r=a*b*c/(4*s);
    A=acos(1-a*a/r/r/2);
    B=acos(1-b*b/r/r/2);
    C=2*pi-A-B;
}

int main(int argc, char const *argv[])
{
    init();
    ans=pi/fgcd(A,fgcd(B,C))*r*r*sin(fgcd(A,fgcd(B,C)));
    printf("%.8lf\n",ans);
    return 0;
}
