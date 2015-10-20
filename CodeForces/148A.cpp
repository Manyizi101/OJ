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
int k,l,m,n,d,ans;
int vis[maxn];

int main()
{
    while(~scanf("%d%d%d%d%d", &k, &l, &m, &n, &d)) {
        memset(vis,0,sizeof(vis));
        ans = 0;
        for(int i=0; i<=d; i+=k) {
            vis[i]=1;
        }
        for(int i=0; i<=d; i+=l) {
            vis[i]=1;
        }
        for(int i=0; i<=d; i+=m) {
            vis[i]=1;
        }
        for(int i=0; i<=d; i+=n) {
            vis[i]=1;
        }
        vis[0]=0;
        for(int i=0; i<=d; ++i) {
            if(vis[i]) ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
