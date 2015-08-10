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

const int maxn = 25;

int t,m,n,k,ans;
int dir[4][2]= {{-1,0},{1,0},{0,1},{0,-1}};

struct node
{
    int k,vis,bu,val;
} a[maxn][maxn];

bool judge(int x,int y)
{
    if(1<=x&&x<=m&&1<=y&&y<=n&&a[x][y].vis==0)  return true;
    else return false;
}

int bfs()
{
    a[1][1].vis=1;
    a[1][1].bu++;
    a[1][1].k=k;
    if(a[1][1].val)
    {
        a[1][1].k--;
    }
    if(a[1][1].k<0) return -1;
    queue<pair<int,int> > q;
    q.push(make_pair(1,1));
    while(!q.empty())
    {
        int ty = q.front().first;
        int tx = q.front().second;
        q.pop();
        //cout<<q.front().first<<" "<<q.front().second<<endl;

        for(int i=0; i<4; ++i)
        {
            if(judge(ty+dir[i][0],tx+dir[i][1]))
            {
                a[ty+dir[i][0]][tx+dir[i][1]].vis=1;
                if(a[ty+dir[i][0]][tx+dir[i][1]].val)
                {
                    a[ty+dir[i][0]][tx+dir[i][1]].k=a[ty][tx].k-1;
                }
                else
                {
                    a[ty+dir[i][0]][tx+dir[i][1]].k=k;
                }
                if(a[ty+dir[i][0]][tx+dir[i][1]].k<0)
                {
                    a[ty+dir[i][0]][tx+dir[i][1]].k=a[ty][tx].k;
                    continue;
                }
                else
                {
                    q.push(make_pair(ty+dir[i][0],tx+dir[i][1]));
                    a[ty+dir[i][0]][tx+dir[i][1]].bu=a[ty][tx].bu+1;
                }
            }
        }
    }
    return  a[m][n].bu;
}
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        memset(a,0,sizeof(a));
        scanf("%d%d%d", &m,&n,&k);
        for(int i=1; i<=m; ++i)
        {
            for(int j=1; j<=n; ++j)
            {
                scanf("%d", &a[i][j].val);
            }
        }
        if(n==m&&n==1)  ans=0;
        else
            ans=bfs();
        printf("%d\n", ans);
    }
}


































