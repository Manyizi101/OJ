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


const int maxn = 1e5+10;7

int n,a[maxn];

int main()
{
    while(~scanf("%d", &n))
    {
        int ans=0;
        for(int i=0; i<n; ++i)
        {
            scanf("%d", &a[i]);
            ans^=a[i];
        }
        if(ans) puts("Win");
        else puts("Lose");
    }
}
