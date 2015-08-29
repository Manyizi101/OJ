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

const int maxn = 10010;

int n,m;
int a[maxn][maxn];

int main()
{
    scanf("%d%d", &n,&m);
    for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j)
            scanf("%d", &a[i][j]);
    int x,y;
    while(scanf("%d", &x)!=0)
    {
        scanf("%d", &y);
        int ans=0;
        int l=0,r=m-1;
        for(int i=n-1; i>=0; --i)
        {
            while(a[i][l]<x&&l<m)   l++;
            ans-=l;
        }
        for(int i=0; i<n; ++i)
        {
            while(a[i][r]>y&&r>=0)  r--;
            ans+=r+1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
