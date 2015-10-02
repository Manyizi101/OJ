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

const int maxn = 30;

int t;
ll ans[maxn],cnt;
int l1,r1,l2,r2;
int cs=0;

int main()
{
    for(int i=1;i<=10;++i)
    {
        for(int j=1;j<=10;++j)
        {
            printf("%3d", (i^j));
        }
        cout<<endl;
    }
    scanf("%d", &t);
    while(t--)
    {
        cnt=0;
        scanf("%d%d%d%d", &l1,&r1,&l2,&r2);
        for(int i=max(r1-7,l1); i<=r1; ++i)
        {
            ans[cnt]=inf;
            for(int j=l2; j<=min(l2+7,r2); ++j)
            {
                ll tmp=(i^j);
                ans[cnt]=min(tmp,ans[cnt]);
            }
            cnt++;
        }
        sort(ans,ans+cnt);
        printf("Case #%d: ", ++cs);
        printf("%I64d\n", ans[cnt-1]);
    }
}
