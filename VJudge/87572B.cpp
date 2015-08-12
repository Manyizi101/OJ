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

const int maxn = 50+10;

int n,m;
int a[maxn][maxn];
int ansx,ansy;


int main()
{
    while(~scanf("%d%d", &n,&m))
    {
        ansx=0,ansy=0;
        for(int i=1; i<=n; ++i)
        {
            for(int j=1; j<=m; ++j)
            {
                scanf("%d", &a[i][j]);
                if(a[i][j]>0)
                {
                    ansx=max(ansx,i);
                    ansy=max(ansy,j);
                }
            }
        }
        printf("%d\n", ansx+ansy);
    }
}
