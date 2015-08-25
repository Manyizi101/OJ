#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cassert>
#include <map>
using namespace std;
typedef long long ll;
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
