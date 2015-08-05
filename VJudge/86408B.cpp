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



const int NP = 1000005;
int ispri[NP] = {}, prime[NP], pcnt = 0;
void getprime()
{
    ispri[0] = ispri[1] = 1;
    for (long long i = 2; i < NP; i++)
        if (ispri[i] == 0)
        {
            prime[++pcnt] = i;
            for (long long j = i * i; j < NP; j += i)
                ispri[j] = 1;
        }
}

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

ll gcdx(ll a, ll b)
{
    for (i = 1; i <= sqrt(n); i++)
    {
        while (n != prime[i])
        {
            if (n % prime[i] == 0)
            {
                return prime[i];
            }
        }
    }
}

int t;
ll x, y, k;

ll dfs(ll x, ll y, ll k)
{
    if (gcd(x, y) == 1) break;
    else
    {
        ll tmp = gcdx(x, y);
        dfs(x/tmp,y/tmp,)
    }
}

int main()
{
    getprime();
    scanf("%d", &t);
    while (t--)
    {
        scanf("%I64d%I64d%I64d", &x, &y, &k);

    }
    return 0;
}