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
#define debug "output for debug\n"
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf 0x3f3f3f3f
#define ll long long int
using namespace std;

#define MAXN 5000000+10
#define MOD  1000000007
#define BIG  10000009

char a[MAXN],s[MAXN<<1];
ll n,l[MAXN],r[MAXN],dp[MAXN];
ll i,j,len;
ll ans = 0;

void init()
{
    scanf("%s", a);
    dp[0]=0;
    for(i=0; a[i]; i++)
    {
        if('0'<=a[i]&&a[i]<='9')
            a[i] = a[i]-'0';
        else if('a'<=a[i]&&a[i]<='z')
            a[i] = a[i]-'a'+10;
        else
            a[i] = a[i]-'A'+36;
    }
}

int main(int argc, char const *argv[])
{
    init();
    len = i;
    l[0] = 0;
    ll tmp = 1;
    for(i=1; i<=len; i++)
    {
        l[i] = (l[i-1]+a[i-1]*tmp)%MOD;
        tmp = (tmp*BIG)%MOD;
    }

    r[len+1] = 0;
    for(i=1; i<=len; i++)
    {
        r[i] = (r[i-1]*BIG+a[i-1])%MOD;
    }

    ans=0;
    for(i=1; i<=len; i++)
    {
        if(l[i]==r[i])
        {
            dp[i] = dp[i>>1]+1;
            ans += dp[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}
