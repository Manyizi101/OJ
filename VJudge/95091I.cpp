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
const int INF = 1<<30;
using namespace std;

const int maxn = 4000+10;

struct IntervalTree2D {
    int Max[maxn][maxn], Min[maxn][maxn],n,m;
    int xo, xleaf,x1,y1,x2,y2,x,y,v,vmax,vmin;

    void query1D(int o, int L, int R)
    {
        if(y1<=L&&R<=y2) {
            vmax = max(Max[xo][o],vmax);
            vmin = min(Min[xo][o],vmin);
        } else {
            int M = L + (R-L)/2;
            if(y1<=M) query1D(o*2, L, M);
            if(M<y2)    query1D(o*2+1, M+1, R );
        }
    }

    void query2D(int o, int L, int R)
    {
        if(x1<=L&&R<=x2)    {
            xo=o;
            query1D(1,1,m);
        } else {
            int M = L+(R-L)/2;
            if(x1<=M)   query2D(o*2,L,M);
            if(M<x2)    query2D(o*2+1,M+1,R);
        }
    }

    void modify1D(int o, int L, int R)
    {
        if(L==R) {
            if(xleaf) {
                Max[xo][o]=Min[xo][o]=v;
                return;

            }
            Max[xo][o] = max(Max[xo*2][o],Max[xo*2+1][o]);
            Min[xo][o]= min(Min[xo*2][o],Min[xo*2+1][o]);
        } else {
            int M = L +(R-L)/2;
            if(y<=M)modify1D(o*2,L,M);
            else modify1D(o*2+1,M+1,R);
            Max[xo][o] = max(Max[xo][o*2],Max[xo][o*2+1]);
            Min[xo][o]= min(Min[xo][o*2],Min[xo][o*2+1]);
        }
    }

    void modify2D(int o, int L, int R)
    {
        if(L==R)    {
            xo=o;
            xleaf=1;
            modify1D(1,1,m);
        } else {
            int M = L +(R-L)/2;
            if(x<=M)    modify2D(o*2,L,M);
            else modify2D(o*2+1,M+1,R);
            xo=o;
            xleaf=0;
            modify1D(1,1,m);
        }
    }

    void query()
    {
        vmax = -INF;
        vmin = INF;
        query2D(1,1,n);
    }

    void modify()
    {
        modify2D(1,1,n);
    }
};

IntervalTree2D t;

int main()
{
    int n,m,cs;
    int ccs=0;
    int x,y,l;
    scanf("%d", &cs);
    while(cs--) {
        printf("Case #%d:\n", ++ccs);
        scanf("%d", &n);
        t.n=n;
        t.m=n;
        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=n; ++j) {
                scanf("%d", &t.v);
                t.x=i;
                t.y=j;
                t.modify();
            }
        }
        scanf("%d", &m);
        while(m--) {
            scanf("%d%d%d", &t.x,&t.y,&l);
            t.x1 = max(1,t.x-(l-1)/2);
            t.y1 = max(1,t.y-(l-1)/2);
            t.x2 = min(n,t.x+(l-1)/2);
            t.y2 = min(n,t.y+(l-1)/2);
            t.query();
            //cout<<t.vmin<<endl;
            t.v = (t.vmax + t.vmin) / 2;
            printf("%d\n",t.v);
            t.modify();

        }
    }
}
