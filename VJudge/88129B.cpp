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

const int maxn = 1000+10;

int t,n;
ll a[maxn];
ll cnt[maxn],dp[maxn];

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i=0; i<n; ++i)    scanf("%I64d", &a[i]);
        memset(dp, 0, sizeof(dp));
        memset(cnt,0,sizeof(cnt));
        ll Max;
        for (int i = 0; i < n; ++i)
        {
            bool flag=false;
            Max = 0;
            for (int j = 0; j < i; ++j)
            {
                if (a[i] > a[j])
                {
                    Max = max(Max, dp[j]);
                }
                else if (a[i]==a[j])
                {
                    flag=true;
                }
            }
            dp[i] = Max + 1;
            if(flag)
                cnt[dp[i]]+=2;
            else
                cnt[dp[i]]+=1;
        }
        ll tmp=0;
        for(int i=n; i>=1; --i)
        {
            cout<<cnt[i]<<" ";
            if(cnt[i]>=1)
            {
                tmp = i;
            }
            /*
            else if(cnt[i]==1)
            {
                tmp = i-1;
            }
            **/
            Max = max(tmp,Max);
        }
        cout<<endl;
        printf("%I64d\n", Max);
    }
}

