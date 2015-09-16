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

const int maxn = 100000+10;

int t;
ll n;
ll x[maxn];
ll k;

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%I64d%I64d", &n, &k);
        for(ll i=1; i<=n; ++i)
        {
            scanf("%I64d", &x[i]);
        }
        sort(x+1,x+n+1);
        ll sum=0;
        for(int i=1;i<=n;++i)
        {
            int pos = upper_bound(x+i,x+n+1,x[i]+k)-x-i;
            sum += n - max(n-pos,(ll)0);
        }
        printf("%I64d\n", sum - n);
    }
}
