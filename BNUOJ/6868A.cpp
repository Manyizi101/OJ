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
const int N = 310;
const int INF = 0x3f3f3f3f;
int nx,ny;//两边的点数
double g[N][N];//二分图描述
double x1[N],x2[N],y1[N],y2[N];
int linker[N],lx[N],ly[N];//y中各点匹配状态，x,y中的点标号
int slack[N];
bool visx[N],visy[N];
double dis(double xx1,double yy1,double xx2,double yy2)
{
    return sqrt((xx1 - xx2)*(xx1-xx2) + (yy1-yy2)*(yy1-yy2));
}
bool DFS(int x)
{
    visx[x] = true;
    for(int y = 0; y < ny; y++)
    {
        if(visy[y])continue;
        int tmp = lx[x] + ly[y] - g[x][y];
        if(tmp == 0)
        {
            visy[y] = true;
            if(linker[y] == -1 || DFS(linker[y]))
            {
                linker[y] = x;
                return true;
            }
        }
        else if(slack[y] > tmp)
            slack[y] = tmp;
    }
    return false;
}
double KM()
{
    memset(linker,-1,sizeof(linker));
    memset(ly,0,sizeof(ly));
    for(int i = 0; i < nx; i++)
    {
        lx[i] = -INF;
        for(int j = 0; j < ny; j++)
            if(g[i][j] > lx[i])
                lx[i] = g[i][j];
    }
    for(int x = 0; x < nx; x++)
    {
        for(int i = 0; i < ny; i++)             slack[i] = INF;
        while(true)
        {
            memset(visx,false,sizeof(visx));
            memset(visy,false,sizeof(visy));
            if(DFS(x))break;
            int d = INF;
            for(int i = 0; i < ny; i++)
                if(!visy[i] && d > slack[i])
                    d = slack[i];
            for(int i = 0; i < nx; i++)
                if(visx[i])
                    lx[i] -= d;
            for(int i = 0; i < ny; i++)
            {
                if(visy[i])ly[i] += d;
                else slack[i] -= d;
            }
        }
    }
    double res = 0;
    for(int i = 0; i < ny; i++)
        if(linker[i] != -1)
            res += g[linker[i]][i];
    return res;
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i = 0 ; i< n ; i ++) scanf("%lf%lf",&x1[i],&y1[i]);
        for(int i = 0 ; i< n ; i ++) scanf("%lf%lf",&x2[i],&y2[i]);
        for(int i = 0 ; i< n ; i++)
        {
            for(int j = 0; j<n; j++)
            {
                g[i][j] = dis(x1[i],y1[i],x2[j],y2[j]);
            }
        }
        nx = ny = n;
        printf("%f\n",KM());
    }
}
