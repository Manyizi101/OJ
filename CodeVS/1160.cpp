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
#define inf (1<<28)
#define ll long long int
using namespace std;

#define MAXN 1000

int n,u[MAXN][MAXN],x,y,i,j,t,s=0;

int main(int argc, char const *argv[])
{
    scanf("%d",&n);
    for(i=n/2+1,t=1; i<=n; ++i,t+=2)
    {
        u[i][i]=t*t;
        x=y=i;
        while(y>i-t+1)
            --y,u[x][y]=u[x][y+1]-1;
        while(x>i-t+1)
            --x,u[x][y]=u[x+1][y]-1;
        while(y<i)
            ++y,u[x][y]=u[x][y-1]-1;
        while(x<i-1)
            ++x,u[x][y]=u[x-1][y]-1;
    }
    for(i=1; i<=n; ++i)
    {
        for(j=1; j<=n; ++j)
        {
            printf("%d ",u[i][j]);
            s+=((i==j||i+j==n+1)?u[i][j]:0);
        }
        printf("\n");
    }
    printf("%d",s);
    return 0;
}

