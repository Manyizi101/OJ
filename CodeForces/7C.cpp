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
#define inf 0x3f3f3f3f
#define ll long long int
using namespace std;

ll a,b,c,d,x,y;

void ex_gcd(ll a, ll b, ll& d,ll& x, ll& y)
{
    if(!b)
    {
        d=a;
        x=1;
        y=0;
    }
    else
    {
        ex_gcd(b,a%b,d,y,x);
        y -= x*(a/b);
    }
}

int main(int argc, char const *argv[])
{
    cin >> a >> b >> c;
    ex_gcd(a,b,d,x,y);
    if(c%d != 0)
        puts("-1");
    else
        cout << -x*(c/d) << " " << -y*(c/d) << endl;
    return 0;
}
