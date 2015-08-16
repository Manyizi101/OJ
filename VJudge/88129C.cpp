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

const int maxn  = 1000+10;
int t,n;
ll a[maxn],ans[maxn];
bool flag;

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        flag=false;
        scanf("%d",&n);
        a[0]=0;
        ans[0]=0;
        for(int i=1; i<=n; ++i)
        {
            scanf("%I64d", &a[i]);
            ans[i]=ans[i-1]^a[i];
        }
        if(n==1)
        {
            printf("NO\n");
            continue;
        }
        for(int i=1;i<=n;++i)
        {
            if(ans[i]==0)   flag=true;
        }
        if(flag)    printf("YES\n");
        else printf("NO\n");
    }
}

