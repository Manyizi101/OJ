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
using namespace std;
typedef long long LL;
const double INF = 1e40;
const double eps  =1e-8;
const int N = 50105;
int dp[2][50][3];
int a[N];
int main()
{
    int T,n,cs = 1;
    scanf("%d",&T);
    while(T--) {
        memset(dp,0,sizeof(dp));
        unsigned long long  ans = 0;
        scanf("%d",&n);
        double tot = n*(n+1)/2;
        for(int i = 0; i < n ; i++) scanf("%d",&a[i]);
        printf("Case #%d: ",cs++);
        for(int i = 0 ; i<n; i++) {
            for(int j = 0; j<33; j++) dp[i%2][j][0] = dp[i%2][j][1] = 0;
            for(int j = 0; j<33; j++) {
                if(a[i] & (1<<j)) {
                    dp[i%2][j][0] = dp[(i+1)%2][j][0];
                    dp[i%2][j][1] = dp[(i+1)%2][j][1] + 1;
                } else {
                    dp[i%2][j][0] = dp[(i+1)%2][j][0] + dp[(i+1)%2][j][1] + 1;
                    dp[i%2][j][1] = 0;
                }
            }
            for(int j = 0; j<33; j++) ans += dp[i%2][j][1]*(1<<j);
        }
        printf("%.6f ",ans*1.0/tot);
        memset(dp,0,sizeof(dp));
        ans = 0;
        for(int i = 0 ; i<n; i++) { ///or
            for(int j = 0; j<33; j++) dp[i%2][j][0] = dp[i%2][j][1] = 0;
            for(int j = 0; j<33; j++) {
                if(a[i] & (1<<j)) {
                    dp[i%2][j][0] = 0;
                    dp[i%2][j][1] = dp[(i+1)%2][j][1] + dp[(i+1)%2][j][0] + 1;
                } else {
                    dp[i%2][j][0] = dp[(i+1)%2][j][0] + 1;
                    dp[i%2][j][1] = dp[(i+1)%2][j][1];
                }
            }
            for(int j = 0; j<33; j++) ans += dp[i%2][j][1]*(1<<j);
        }

        printf("%.6f ",ans*1.0/tot);
        ///xor
        ans = 0;
        memset(dp,0,sizeof(dp));
        for(int i = 0 ; i<n; i++) {
            for(int j = 0; j<33; j++) dp[i%2][j][0] = dp[i%2][j][1] = 0;
            for(int j = 0; j<33; j++) {
                if(a[i] & (1<<j)) { /// dangqianwei 1
                    dp[i%2][j][0] = dp[(i+1)%2][j][1];
                    dp[i%2][j][1] = dp[(i+1)%2][j][0] + 1;
                } else {
                    dp[i%2][j][0] = dp[(i+1)%2][j][0] + 1;
                    dp[i%2][j][1] = dp[(i+1)%2][j][1] ;
                }
            }
            for(int j = 0; j<33; j++) ans += dp[i%2][j][1]*(1<<j);
        }
        printf("%.6f\n",ans*1.0/tot);
    }
    return 0;
}
