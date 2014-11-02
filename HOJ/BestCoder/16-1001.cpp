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
#define inf (1<<28)
#define ll long long int
using namespace std;

#define mod 1000000007

ll t,n;
ll tmp,ans=0;
ll a,b,c;

int main(int argc, char const *argv[])
{
    scanf("%I64d", &t);
    while(t--)
    {
        ans=0,tmp=0;
        scanf("%I64d", &n);
        for(int i=1; i<=n; i++)
        {
            scanf("%I64d", &tmp);
            a=(n+1)*i%mod;
            b=i*i%mod;
            ans+=(a-b)*(tmp%mod);
            ans%=mod;
        }
        printf("%I64d\n", ans%mod);
    }
    return 0;
}
