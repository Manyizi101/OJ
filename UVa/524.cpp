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

#define MAXN 50

int n,flag=0;
int A[MAXN],isp[MAXN],vis[MAXN];

bool isPrime(int x)
{
    for(int j=2; j<=(int)sqrt(x); j++)
    {
        if(x%j==0)  return false;
    }
    return true;
}

void dfs(int cur)
{
    if(cur==n && isp[A[0]+A[n-1]])
    {
        for(int i=0; i<n; i++)
        {
            printf("%d", A[i]);
            if(i!=n-1)  printf("%c", ' ');
        }
        printf("\n");
    }
    else
        for(int i=2; i<=n; i++)
        {
            if((!vis[i]&&isp[i+A[cur-1]]))
            {
                A[cur]=i;
                vis[i]=1;
                dfs(cur+1);
                vis[i]=0;
            }
        }
}

int main(int argc, char const *argv[])
{

    for(int i=1; i<100; i++)
    {
        if(isPrime(i))  isp[i]=i;
        else isp[i]=0;
    }
    while(~scanf("%d", &n))
    {
        flag++;
        if(flag>1)
            printf("\n");
        printf("Case %d:\n", flag);
        memset(vis,0,sizeof(vis));
        A[0]=1;
        vis[1]=1;
        dfs(1);
    }
    return 0;
}
