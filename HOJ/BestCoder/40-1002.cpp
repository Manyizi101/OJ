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
#define ll long long int
const double pi = acos(-1.0);
const double eps = (1e-8);
const int inf = 1<<31;
using namespace std;

const int N = 1505;


ll dp[N][N];
int pre[N][N];
int main(int argc, char const *argv[])
{
    int t,cs = 0;
    cin>>t;
    while(t--)
    {
    	memset(dp,0,sizeof(dp));
    	memset(pre,0,sizeof(pre));
    	ll n,x,y,z,t ; ///x throng y after z jiansu
    	cin>>n>>x>>y>>z>>t;
    	ll ans = 0;
        for(ll i=0;i<=n;i++)  ///y
        {
        	for(ll j=0;j+i<=n;j++) ///z
        	{
        		if(i>0) dp[i][j] = dp[i-1][j]+max((z*j+t)*y*(n-i-j),t*y*(i+j));
        		if(j>0) dp[i][j] = max(dp[i][j],dp[i][j-1] + i*z*y);
        		ans = max(ans,dp[i][j] + (n-i-j)*x*(j*z+t));
        	}
        }
      printf("Case #%d: %I64d\n",++cs,ans );
      
    }
	return 0;
}