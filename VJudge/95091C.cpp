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
const int N  =11000;
const int maxn = 110;

int dp[400005];
int a[N];
int main()
{
    int T,n,m;
    scanf("%d",&T);
    while(T--) {
        double p;
        int sum = 0 ;
        memset(dp,0,sizeof(dp));
        scanf("%d%lf",&n,&p);
        for(int i = 0 ; i<n; i++) {
            scanf("%d",&a[i]);
            sum += a[i];
        }
        int s = ceil(sum*1.0*p);
        dp[a[0]] = 1;
        for(int i = 1 ; i< n; i++) {
            dp[a[i]] = 1;
            for(int j =  sum; j>=0; j--) {
                if(j-a[i]>=0) dp[j] = max(dp[j],dp[j-a[i]]);
            }
        }
        for(int i = s; i<=sum; i++) {
            if(dp[i]) {
                printf("%d\n",i);
                break;
            }
        }
    }
}
