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

int n;

const int CN = 50;
long long c[CN][CN] = {};

void init()
{
    for(int i = 0;i<CN;++i)
    {
        c[i][0] = c[i][i]=1;
        for(int j=1;j<i;++j)
        {
            c[i][j]=c[i-1][j]+c[i-1][j-1];
        }
    }
}

int main()
{
    init();
    for(int n=1; n<=20; ++n)
    {
        ll ans=1;
        for(int i=0; i<=n; ++i)
        {
            ans = ans*c[n][i]/__gcd(ans,c[n][i]);
        }
        printf("%I64d    ", c[n][n/2]*c[n][n/2-1]/__gcd(c[n][n/2],c[n][n/2-1]));
        printf("%I64d\n", ans);
    }
}
