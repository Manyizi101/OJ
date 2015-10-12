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

const int maxn = 40;

int n;
int a[maxn][maxn];

int main()
{
    while(~scanf("%d", &n))
    {
        int ans =0;
        memset(a,0,sizeof(a));
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                scanf("%d", &a[i][j]);
                if(a[i][j]==1)  ans++;
            }
        }
        printf("%d\n", ans+2*n);
    }
}
