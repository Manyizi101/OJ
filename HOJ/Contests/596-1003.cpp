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

const int mod = 258280327;

int lcm(int a, int b)
{
    return a*b/__gcd(a,b);
}

int main()
{
    int ans=0;
    int old=0;
    int tmp=0;
    freopen("596-1003.out","w",stdout);
    for(int n=1; n<=100; ++n)
    {
        tmp=0;
        for(int i=1; i<=n; ++i)
        {
            for(int j=1; j<=n; ++j)
            {
                if(lcm(i,j)+__gcd(i,j)>=n)   tmp+=1;
            }
        }
        printf("%d\n", n*n-tmp);
    }
}

