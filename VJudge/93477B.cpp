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


const int maxn = 100005;

int t,n;
int tmp,gao[maxn];

void pdec(int n)
{
    gao[n]++;
    gao[1]++;
    for (int i = 2; i*i <= n; i++)
    {
        if(n%i==0)
        {
            gao[n/i]++;
            gao[i]++;
        }
    }
}

int cs=0;

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        int Max = 0;
        memset(gao,0,sizeof(gao));
        scanf("%d", &n);
        for(int i=0; i<n; ++i)
        {
            scanf("%d", &tmp);
            Max =max(tmp,Max);
            pdec(tmp);
        }
        printf("Case #%d: ", ++cs);
        for(int i=Max; i>=1; --i)
        {
            if(gao[i]>=2)
            {
                printf("%d\n", i);
                break;
            }
        }
    }
}
