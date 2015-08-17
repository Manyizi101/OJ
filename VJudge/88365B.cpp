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

const int maxn = 1010;
int t,n,k;
int a[maxn];
int m,v;
ll ans;

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        ans=0;
        memset(a,0,sizeof(a));
        scanf("%d%d", &n, &k);
        for(int i=0; i<n; ++i)
        {
            scanf("%d", &m);
            for(int j=0; j<m; ++j)
            {
                scanf("%d", &v);
                if(v>=k) a[i]++;
            }
        }
        for(int i=0; i<n-1; ++i)
        {
            for(int j=i+1; j<n; ++j)
            {
                ans+=a[i]*a[j];
            }
        }
        printf("%I64d\n", ans);
    }
}

