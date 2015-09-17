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

const int maxn = 50000+10;
ll a[maxn],sum,sums;

int main()
{
    int t,n,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for(int i = 1; i<=n; i++)
            scanf("%I64d", &a[i]);
        if(n==k)
        {
            printf("0\n");
            continue;
        }
        sort(a+1,a+n+1);
        sum=sums=0;
        for(int i = 1; i<=n-k; i++)
        {
            sum += a[i];
            sums += a[i] * a[i];
        }
        double ave  = sum*1.0/(n-k);
        double mini = sums + (n-k)*ave*ave - 2*sum*ave;
        for(int i = 1 ; i <= k; i++)
        {
            sum = sum - a[i]+a[n-k+i];
            sums = sums - a[i]*a[i]+ a[n-k+i]*a[n-k+i];
            ave = sum*1.0/(n-k);
            double temp  = sums + (n-k)*ave*ave - 2*sum*ave;
            if(temp < mini)
            {
                mini = temp;
            }
        }
        printf("%.10f\n",mini);
    }
}
