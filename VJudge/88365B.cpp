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

const int maxn = 1010;
int t,n,k;
int a[maxn*maxn];
int b[maxn][maxn];
int len=0;
int m[maxn];
ll ans1,ans2;

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        ans1=ans2=0;
        len=0;
        scanf("%d%d", &n, &k);
        for(int i=0; i<n; ++i)
        {
            scanf("%d", &m[i]);
            for(int j=0; j<m[i]; ++j)
            {
                scanf("%d", &b[i][j]);
                a[len++]=b[i][j];
            }
            sort(b[i],b[i]+m[i]);
        }
        sort(a,a+len);
        for(int i=1; i<len; ++i)
        {
            if(a[i-1]>k) ans1+=len-i;
            else
            {
                int pos=upper_bound(a+i,a+len,k-a[i-1])-a;
                ans1+=len-pos;
            }
        }
        for(int j=0; j<n; ++j)
        {
            if(m[j]==1) continue;
            for(int i=1; i<m[j]; ++i)
            {
                if(b[j][i-1]>k)
                {
                    ans2+=m[j]-i;
                }
                else
                {
                    int pos=upper_bound(b[j]+i,b[j]+m[j],k-b[j][i-1])-b[j];
                    ans2+=m[j]-pos;
                }
            }
        }
        printf("%I64d\n", ans1-ans2);
    }
}

