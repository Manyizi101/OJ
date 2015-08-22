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

const int maxn = 1e5+10;
int na,nb,m,k;
int a[maxn],b[maxn];

int main()
{
    while(~scanf("%d%d", &na,&nb))
    {
        scanf("%d%d", &k,&m);
        for(int i=1;i<=na;++i)  scanf("%d", &a[i]);
        for(int i=1;i<=nb;++i)  scanf("%d", &b[i]);
        if(a[k]<b[nb-m+1])   printf("YES\n");
        else printf("NO\n");
    }
}
