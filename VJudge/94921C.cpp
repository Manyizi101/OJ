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

const int maxn = 110;

int n,m,k;
int w[maxn][maxn];
int dp[maxn][maxn][maxn];

int main()
{
    while(~scanf("%d%d%d", &n,&m,&k)) {
        memset(dp,0,sizeof(dp));
        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=m; ++j) {
                scanf("%d", &w[i][j]);
            }
        }
        for(int c=k; c>=0; --c) {
            for(int i=1; i<=n; ++i) {
                for(int j=1; j<=m; ++j) {
                    dp[i][j][c]=max(dp[i-1][j][c],dp[i][j-1][c]);
                    if(c+w[i][j]<=k) {
                        dp[i][j][c]=max(dp[i][j][c],max(dp[i-1][j][c+w[i][j]],dp[i][j-1][c+w[i][j]])+w[i][j]);
                    }
                }
            }
        }
        int ans = 0;
        for(int i=0; i<=k; ++i) {
            ans=max(ans,dp[n][m][i]);
        }
        cout<<ans<<endl;
    }
}
