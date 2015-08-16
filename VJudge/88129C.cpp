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

const int maxn = 205;
double a[maxn][maxn]={0},ans[maxn]={0};
bool l[maxn];
int n;

inline int solve(double a[][maxn],bool l[],double ans[],const int& n)
{
    int res=0,r=0;
    for(int i=0;i<n;++i)    l[i]=0;
    for(int i=0;i<n;++i)
    {
        for(int j=r;j<n;++j)
        {
            if(fabs(a[j][i])>eps)
            {
                for(int k=i;k<=n;++k)
                {
                    swap(a[j][k],a[r][k]);

                }
                break;
            }
            if(fabs(a[r][i]<eps))
            {
                res++;
                continue;
            }
            for(int j=0;j<n;++j)
            {
                if(j!=r&&fabs(a[j][i])>eps)
                {
                    double tmp = a[j][i]/a[r][i];
                    for(int k=i;k<=n;++k)
                    {
                        a[j][k]-=tmp*a[r][k];
                    }
                }
            }
            l[i]= true, r++;
        }
        for(int i=r;i<n;++i)
        {
            if(fabs(a[i][n])>eps)   return -1;
        }
        for(int i=0;i<n;++i)
        {
            if(l[i])
            {
                for(int j=0;j<n;++j)
                {
                    if(fabs(a[j][i])>eps)
                    {
                        ans[i]=a[j][n]/a[j][i];
                    }
                }
            }
        }
    }
    return res;
}


int main()
{

}

