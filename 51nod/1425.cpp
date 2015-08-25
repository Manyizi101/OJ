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

const int N = 300005;
map< pair<ll , ll> , pair<ll , ll> > f;
pair<ll , ll> dfs(ll x , ll y)
{
    if (x == 0)
        return make_pair(x || y , -y);
    if (x < 10)
        return make_pair(1ll , x - max(x , y));
    if (f.count({x , y}))
        return f[ {x , y} ];
    ll ans = 0 , p = 1;
    while (p <= x / 10)
        p *= 10;
    pair<ll , ll> r = dfs(x % p , max(y , x / p));
    pair<ll , ll> b = dfs(x / p * p + r.second , y);
    ans = r.first + b.first;
    return f[ {x , y}] = make_pair(ans , b.second);
}

ll n;

int main()
{
    while(cin>>n)
    {
        cout << dfs(n , 0).first << endl;
    }
    return 0;
}
