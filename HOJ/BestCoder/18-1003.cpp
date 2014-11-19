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

#define MAXN 1000+10

int n;
char bit[MAXN];
ll ans[MAXN]
int len;

int cnm(int n, int m)
{
    return m==0?1:cnm(n-1,m-1)*n/m;
}

int main(int argc, char const *argv[])
{
    while(~scanf("%d", &n))
    {
        scanf("%s", bit);
        len=strlen(bit);
        memset(ans,0,sizeof(int)*len);
        ans[0]=0;
        ans[1]=
    }
    return 0;
}
