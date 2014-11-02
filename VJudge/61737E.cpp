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
#define inf (1<<28)
#define ll long long int
using namespace std;

#define MAXN 100000+10

int n;
int bott[MAXN];
ll ans;
int i;

int main(int argc, char const *argv[])
{
    while(scanf("%d" , &n) && n)
    {
        for(i = 0 ; i < n ; i++)
            scanf("%d" , &bott[i]);
        ans = 0;
        for(i = 1 ; i < n ; i++)
        {
            bott[i] += bott[i-1];
            ans += abs(bott[i-1]);
        }
        printf("%lld\n" , ans);
    }

    return 0;
}
