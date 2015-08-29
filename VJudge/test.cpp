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

const int maxn = 10010;

int n,m;
int a[maxn][maxn];

int main()
{
    fread(&n,sizeof(n),1,stdin);
    fread(&m,sizeof(m),1,stdin);
    for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j)
            fread(&a[i][j],sizeof(a[i][j]),1,stdin);
    int x,y;
    while(fread(&x,sizeof(x),1,stdin)!=0)
    {
        fread(&y,sizeof(y),1,stdin);
        int ans=0;
        int l=0,r=m-1;
        for(int i=n-1; i>=0; --i)
        {
            while(a[i][l]<x&&l<m)   l++;
            ans-=l;
        }
        for(int i=0; i<n; ++i)
        {
            while(a[i][r]>y&&r>=0)  r--;
            ans+=r+1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
