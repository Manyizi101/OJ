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

#define MAXN 1000+10

int n;
int a[MAXN][MAXN];
vector<char> route;

void init()
{
    for(int i=0;i<=n;++i)
        for(int j=0;j<=n;++j)
        scanf("%d", &a[i][j]);
}

int dfs(int x,int y)
{
    if(x==3&&y==3)  return 0;
    if(x+1<4&&(a[x+1][y]!=2&&a[x+1][y]!=5))
    {
        route.push_back('R');
        dfs(x+1, y);
    }
    else if(y+1<4&&(a[x][y+1]!=2&&a[x][y+1]!=5))
    {
        route.push_back('D');
        dfs(x,y+1);
    }
    else if(x+1<4&&(a[x+1][y]==2||a[x+1][y]==5))
    {
        route.push_back('R');
        dfs(x+1,y);
    }
    else
    {
        route.push_back('D');
        dfs(x,y+1);
    }
}

int main()
{
    while(~scanf("%d", &n))
    {
        init();
        dfs(1,1);
        for(vector<int>::iterator it=route.begin();it!=route.end();++it)
        {
            printf("%c", 'a');
        }
    }
    return 0;
}
