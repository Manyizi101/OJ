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

int n,a[maxn];
int x[maxn];

void init()
{
    memset(x,1,sizeof(x));
    for(int i=2; i<=1000; ++i)
    {
        for(int j=1; j<i; ++j)
        {
            if(__gcd(i,j)>1)
            {
                x[i]=0;
                break;
            }
        }
    }
    return;
}

int main()
{
    init();
    while(~scanf("%d", &n))
    {
        int sum=0;
        for(int i=0; i<n; ++i)
        {
            scanf("%d", &a[i]);
            if(x[a[i]]) sum+=a[i];
        }
        printf("%d\n",sum);
    }
}
