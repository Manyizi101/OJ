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
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<20)
#define ll long long int
using namespace std;

#define MAXN 1000+10

int n, st, ed;
int x[MAXN], y[MAXN];
bool k[MAXN];
int ans = 0;

bool cal(int i,int j)
{
    if((x[i]-st)*(y[j]-ed)==(x[j]-st)*(y[i]-ed))    return true;
    else return false;
}


int main(int argc, char const *argv[])
{
    scanf("%d%d%d", &n, &st, &ed);
    memset(k,false, sizeof(k));
    for(int i=0;i<n;i++)
    {
        scanf("%d%d", &x[i],&y[i]);
    }
    for(int i=0;i<n;i++)
    {
        if(!k[i])
        {
            for(int j=0;j<n;j++)
            {
                if(cal(i,j))    k[j]=true;
            }
            ans++;
        }
    }
    cout << ans;
    return 0;
}
