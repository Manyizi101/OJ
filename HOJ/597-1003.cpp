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

ll euler[maxn];
ll ans[maxn]= {0};
void Init()
{
    euler[1]=1;
    for(int i=2; i<maxn; i++)
        euler[i]=i;
    for(int i=2; i<maxn; i++)
        if(euler[i]==i)
            for(int j=i; j<maxn; j+=i)
                euler[j]=euler[j]/i*(i-1);
    for(int i=1; i<=maxn; ++i)
    {
        ans[i]+=ans[i-1]-euler[i]+i;
    }
}

int n;

int main()
{
    Init();
    while(~scanf("%d", &n))
    {
        printf("%I64d\n", ans[n]);
    }
}

