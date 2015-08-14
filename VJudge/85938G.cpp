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

const int maxn = 100+10;

int np,nt,nf,cs;
int p[maxn],t[maxn][2][maxn],len[maxn][2];

bool trans()
{
    for(int cs=1; cs<=nt; ++cs)
    {
        //cout<<cs<<endl;
        for(int i=1; i<=len[cs][0]; ++i)
        {
            //cout<<p[t[cs][0][i]]<<endl;
            if(p[t[cs][0][i]]>0)
            {
                p[t[cs][0][i]]--;
                return true;
            }
        }
        for(int i=1; i<=len[cs][1]; ++i)
        {
            p[t[cs][1][i]]++;
        }
        /*
        for(int i=1;i<=np;++i)
        {
            printf("%d %d\n", i, p[i]);
        }
        **/
    }
    return false;
}

int solve()
{
    for(int i=1; i<=nf; ++i)
    {
        if(!trans())    return i;
    }
    return nf;
}

int main()
{
    cs =0 ;
    while(~scanf("%d", &np)&&np)
    {
        //init
        memset(t,0,sizeof(t));
        memset(len,0,sizeof(len));

        //input
        for(int i=1; i<=np; ++i)   scanf("%d",&p[i]);
        scanf("%d", &nt);
        for(int i=1; i<=nt; ++i)
        {
            int tmp;
            while(scanf("%d", &tmp)&&tmp)
            {
                if(tmp<0)   t[i][0][++len[i][0]]=-tmp;
                else t[i][1][++len[i][1]]=tmp;
                //cout<<tmp<<endl;
            }
        }
        scanf("%d", &nf);

        //output
        printf("Case %d: ", ++cs);
        int flag = solve();
        if(flag==nf)
        {
            printf("still live after %d transitions\n", flag);
        }
        else
        {
            printf("dead after %d transitions\n", flag);
        }
        printf("Places with tokens: ");
        for(int i=1; i<=np; ++i)
        {
            if(p[i]>0)
            {
                printf(" %d (%d)", i, p[i]);
            }
        }
        printf("\n\n");
    }
}


/*
2
1 0
2
-1 2 0
-2 1 0
100
3
3 0 0
3
-1 2 0
-2 -2 3 0
-3 1 0
100
0
**/
