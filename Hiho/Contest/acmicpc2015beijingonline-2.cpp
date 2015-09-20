#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<string.h>
#include<math.h>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;
typedef long long LL;
const double eps  = 1e-10;
const int N  = 205;
const int inf = 100000000;
const LL mod = 530600414;
double x[N],y[N];
vector<double> dis[N];

double get_dis(int i,int j)
{
    return sqrt((x[i] - x[j]) * (x[i] - x[j]) +  (y[i] - y[j]) * (y[i] - y[j]));
}

bool judge()
{
    for(int )
}

int main()
{
    int n,m,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&m,&n);
        for(int i = 0 ; i< m ; i++) scanf("%lf%lf",&x[i],&y[i]);
        if(m<n)
        {
            puts("-1");
            continue;
        }
        for(int i = 0 ; i< m ; i++)
        {
            dis[i].clear();
            for(int j = 0; j<m ; j++)
            {
                double t = get_dis(i,j);
                dis[i].push_back(t);
            }
            sort(dis[i].begin(),dis[i].end());
        }
        int mn = inf;
        for(int i = 0; i<m; i++)
        {
            int t = int(dis[i][n-1]) + 1;
            if(n==m) mn = min(mn,t);
            else
            {
                if(fabs(t*1.0-dis[i][n])<=eps) continue;
                if(fabs(t*1.0-dis[i][n-1])<=eps) continue;
                mn = min(mn,t);
            }
        }
        if(mn==inf) puts("-1");
        else printf("%d\n",mn);

    }
    return 0;
}
