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

const int maxn = 5*1e5+10;

int t,n,a[maxn];
vector<int> v[maxn];

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i=0; i<n; ++i)
            scanf("%d", &a[i]);
        int cnt=0;
        v[cnt].push_back(0);
        for(int i=1; i<n; ++i)
        {
            if(a[i]>a[i-1]) v[cnt].push_back(i);
            else
            {
                v[++cnt].push_back(i);
            }
        }
        ll ans=0;
        if(cnt>2)
        {
            ans += (cnt+1)*cnt*(cnt-1)*(cnt-2)/24;
        }
        if(cnt>1)
        for(int i=0;i<=cnt;++i)
        {
            if(v[i].size()>=2)  ans+=((v[i].size()-1)*v[i].size()/2)*((cnt+1)*cnt/2);
        }
    }
    return 0;
}
