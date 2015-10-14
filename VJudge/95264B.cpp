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

const int maxn = 1e5+10;
ll n,p;
ll a[maxn];
ll tmp;

int main()
{
    while(~scanf("%I64d%I64d", &n, &p)) {
        for(int i=0; i<n; ++i) {
            scanf("%I64d", &tmp);
            a[i]=tmp%p;
        }
        sort(a,a+n);
        ll ans=-1;
        for(int i=n-1; i>=0; --i) {
            int flag = lower_bound(a,a+i,p-a[i]-1)-a;
            if(a[flag]==p-a[i]-1) {
                ans = max(ans,p-1);
            } else if(a[flag]>p-a[i]-1) {
                if(flag)
                    ans = max(ans,a[i]+a[flag-1]);
                else
                    continue;
            } else {
                ans = max(ans,a[i]+a[flag]);
            }
        }
        for(int i=n-1; i>=0; --i) {
            int flag = lower_bound(a,a+i,2*p-a[i]-1)-a;
            if(a[flag]==2*p-a[i]-1) {
                ans = max(ans,(2*p-1)%p);
            } else if(a[flag]>2*p-a[i]-1) {
                if(flag)
                    ans = max(ans,(a[i]+a[flag-1])%p);
                else
                    continue;
            } else {
                ans = max(ans,(a[i]+a[flag])%p);
            }
        }
        printf("%I64d\n", ans);
    }
}
