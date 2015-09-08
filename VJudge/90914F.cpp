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

const int maxn = 2*1e5;

int t,n,m,l;
int a[maxn];
int ans=0;

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        ans=0;
        scanf("%d%d%d", &n,&m,&l);
        a[0]=0;
        for(int i=1; i<=n; ++i)    scanf("%d", &a[i]);
        a[n++]=m;
        a[n++]=2*m+l;
        int cur,pre,ans;
        cur=pre=ans=0;
        while(cur<m)
        {
            int rnk = lower_bound(a,a+n,max(cur,pre+l)+l)-a;
            if(a[rnk]==cur+l)
            {
                pre = cur;
                cur += l;
                ans++;
            }
            else
            {
                if(cur<a[rnk-1])
                {
                    pre = cur;
                    cur = a[rnk-1];
                    ans++;
                }
                else
                {
                    int rem = a[rnk]-cur;
                    cur += rem/(l+1)*(l+1);
                    ans += 2*rem/(l+1);
                    pre = cur - l;
                }
            }
        }
        printf("%d\n",ans);
    }
}
