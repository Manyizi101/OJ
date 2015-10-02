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
const double eps = 1e-4;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
using namespace std;

struct point
{
    double x,y,z;
    void in()
    {
        scanf("%lf%lf%lf", &x,&y,&z);
    }
    double dis(point p)
    {
        return sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y)+(z-p.z)*(z-p.z));
    }
};

bool cmp(point a, point b)
{
    if(a.x==b.x&&a.y==b.y)  return a.z<b.z;
    if(a.x==b.x)  return a.y<b.y;
    return a.x<b.x;
}

int t,cs=0;
point a[4];

bool judge()
{
    double d[3];
    for(int i=0; i<3; ++i)
    {
        d[i]=a[0].dis(a[i+1]);
    }
    sort(d,d+3);
    if((fabs(d[0]-d[1])<eps)&&(fabs(d[1]*sqrt(2.0)-d[2]))<eps)  return true;
    else return false;
}

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        for(int i=0; i<4; ++i)    a[i].in();
        printf("Case #%d: ", ++cs);
        if(judge()) puts("Yes");
        else puts("No");
    }
}
