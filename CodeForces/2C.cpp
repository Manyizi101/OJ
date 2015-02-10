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
#define eps (1e-6)
#define inf 0x3f3f3f3f
#define ll long long int
using namespace std;

int dir[4][2]= { {1,0},{-1,0},{0,1},{0,-1} };
double x=0,y=0;

struct node
{
    double x,y,r;
} c[3];

double p2(double x)
{
    return x*x;
}

double dis(double x, double y, double xx, double yy)
{
    return sqrt(p2(x-xx)+p2(y-yy));
}

double f(double x, double y)
{
    double tmp[3],ans=0;
    for(int i=0; i<3; i++)
        tmp[i]=dis(x,y,c[i].x,c[i].y)/c[i].r;
    for(int i=0; i<3; i++)
        ans+=p2(tmp[i]-tmp[(i+1)%3]);
    return ans;
}

void init()
{
    for(int i=0; i<3; i++)
    {
        scanf("%lf%lf%lf", &c[i].x,&c[i].y,&c[i].r);
        x+=c[i].x/3;
        y+=c[i].y/3;
    }
}

int main(int argc, char const *argv[])
{
    init();
    double step=1;
    while(step>eps)
    {
        double tmp=f(x,y);
        int tag=-1;
        for(int i=0; i<4; i++)
        {
            double cnt=f(x+dir[i][0]*step, y+dir[i][1]*step);
            if(cnt<tmp)
            {
                tmp=cnt;
                tag=i;
            }
        }
        if(tag==-1)
        {
            step/=2;
        }
        else
        {
            x=x+dir[tag][0]*step;
            y=y+dir[tag][1]*step;
        }
    }
    if(f(x,y)<eps)
        printf("%.5lf %.5lf\n", x,y);
    return 0;
}
