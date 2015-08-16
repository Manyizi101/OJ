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

const int maxn = 447000+10;
const int mod =  1000000007;

ll ans,a[maxn];
int t,n;

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        ans=0;
        scanf("%d", &n);
        for(int i=1; i<=n; ++i) scanf("%I64d", &a[i]);
        for(int i=1; i<=n; ++i)
        {
            ans=(ans+((i*a[i])%mod*(n-i+1)%mod)%mod)%mod;
        }
        printf("%I64d\n", ans);
    }
}

