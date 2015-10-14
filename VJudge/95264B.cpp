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
        ll ans=(a[n-1]+a[n-2])%p;
        for(int i=0; i<n-2; ++i) {
            int flag = lower_bound(a+i+1,a+n,p-a[i])-a;
            ans=max(ans,(a[i]+a[flag-1])%p);
        }
        printf("%I64d\n", ans);
    }
}
