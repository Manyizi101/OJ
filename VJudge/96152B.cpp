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

const int maxn = 5e4+10;
const ll mod = 998244353;

int t;
int n;
ll a[maxn],ans;
ll x[maxn],y[maxn],nx,ny;

inline ll lowbit(ll x)
{
    return x&(-x);
}

int main()
{
    scanf("%d", &t);
    while(t--) {
        ans=0;
        nx=ny=0;
        scanf("%d",&n);
        for(int i=0; i<n; ++i) {
            scanf("%I64d", &a[i]);
            if(a[i]&1)   x[nx++]=a[i];
            else    y[ny++]=a[i];
        }
        for(int i=0; i<nx-1; ++i) {
            for(int j=i+1; j<nx; ++j) {
                ans += lowbit(x[i]^x[j]);
                ans %= mod;
            }
        }
        for(int i=0; i<ny-1; ++i) {
            for(int j=i+1; j<ny; ++j) {
                ans += lowbit(y[i]^y[j]);
                ans %= mod;
            }
        }
        printf("%I64d\n", (ans*2+nx*ny+n-1)%mod);
    }
}
