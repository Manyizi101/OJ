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

ll phi(ll n)
{
    ll ret = 1, i;
    for (i = 2; i * i <= n; i++)
        if (n % i == 0)
        {
            n /= i;
            ret *= (i - 1);
            while (n % i == 0)
            {
                n /= i;
                ret *= i;
            }
        }
    if (n > 1)
        ret *= (n - 1);
    return ret;
}

ll rub(ll n)
{

    ll x, temp, t, sum = 0;
    for (ll i = 1; i <= n; i++)
    {
        temp = 0;
        x = i;
        do
        {
            t = x % 10;
            temp = temp * 10 + t;
            x = x / 10;
        }
        while (x > 0);
        if (temp == i)
        {

            sum++;
        }
    }
    return sum;
}

int n;
double p, q;

int main()
{
    while(~scanf("%lf%lf", &p,&q))
    {
        for(int ans=1500000; ans>=1; ans--)
        {
            if(phi(ans)*1.0/(double)rub(ans)<42)    printf("%d",ans);
        }
    }
}





























































