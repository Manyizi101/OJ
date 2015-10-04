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
const double eps = 1e-6;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
using namespace std;

const int maxn = 10010;
int n;

struct node
{
    int id;
    double val;
} a[maxn],b[maxn];

bool cmp(node a, node b)
{
    return a.val<b.val;
}
int main()
{
    while(~scanf("%d", &n))
    {
        double tmp;
        int cnta=0,cntb=0;
        for(int i=0; i<n; ++i)
        {
            scanf("%lf", &tmp);
            if(tmp>=0)
            {
                a[cnta].val=tmp;
                a[cnta++].id=i+1;
            }
            else
            {
                b[cntb].val=tmp;
                b[cntb++].id=i+1;
            }
        }
        sort(a,a+cnta,cmp);
        sort(b,b+cntb,cmp);
        int ans[maxn],cnt=0;
        if(cnta>=1)
            for(int i=cnta-1; i>=0; --i)
            {
                if(a[i].val>1) ans[cnt++]=a[i].id;
            }
        if(cntb>=2)
            for(int i=0; i<cntb; i+=2)
            {
                if(b[i].val*b[i+1].val>(1+eps))
                {

                    ans[cnt++]=b[i].id;
                    ans[cnt++]=b[i+1].id;
                }
            }
        sort(ans,ans+cnt);

        if(cnt==0)
        {
            if(cntb>=2)
            {
                if(cnta>=1&&a[cnta-1].val+eps>=b[0].val*b[1].val)
                {
                    cout<<1<<endl<<a[cnta-1].id<<endl;
                }
                else
                {
                    if(b[0].id>b[1].id) swap(b[0],b[1]);
                    cout<<2<<endl<<b[0].id<<" "<<b[1].id<<endl;
                }
            }
            else
                cout<<1<<endl<<a[cnta-1].id<<endl;
            continue;
        }
        printf("%d\n", cnt);
        for(int i=0; i<cnt-1; ++i)
        {
            printf("%d ", ans[i]);
        }
        printf("%d\n", ans[cnt-1]);
    }
}
