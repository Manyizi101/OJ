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
#define eps (1e-8)
#define inf 0x3f3f3f3f
#define ll long long int
using namespace std;

#define MAXN 100+10

char road[MAXN];
int vis[2*MAXN][2*MAXN];
int x=105,y=105,len;

bool solve()
{
    for(int i=0; i<len; i++)
    {
        if(road[i]=='L')
        {
            x-=1;
            if(vis[x][y]==1)    return false;
            int flag=0;
            if(vis[x-1][y]) flag++;
            if(vis[x+1][y]) flag++;
            if(vis[x][y+1]) flag++;
            if(vis[x][y-1]) flag++;
            if(flag>=2) return false;
            vis[x][y]=1;
        }
        else if(road[i]=='U')
        {
            y+=1;
            if(vis[x][y]==1)    return false;
            int flag=0;
            if(vis[x-1][y]) flag++;
            if(vis[x+1][y]) flag++;
            if(vis[x][y+1]) flag++;
            if(vis[x][y-1]) flag++;
            if(flag>=2) return false;
            vis[x][y]=1;
        }
        else if(road[i]=='R')
        {
            x+=1;
            if(vis[x][y]==1)    return false;
            int flag=0;
            if(vis[x-1][y]) flag++;
            if(vis[x+1][y]) flag++;
            if(vis[x][y+1]) flag++;
            if(vis[x][y-1]) flag++;
            if(flag>=2) return false;
            vis[x][y]=1;
        }
        else
        {
            y-=1;
            if(vis[x][y]==1)    return false;
            int flag=0;
            if(vis[x-1][y]) flag++;
            if(vis[x+1][y]) flag++;
            if(vis[x][y+1]) flag++;
            if(vis[x][y-1]) flag++;
            if(flag>=2) return false;
            vis[x][y]=1;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    memset(vis,0,sizeof(vis));
    scanf("%s", road);
    len=strlen(road);
    vis[x][y]=1;
    if(solve()) printf("OK\n");
    else printf("BUG\n");
    return 0;
}
