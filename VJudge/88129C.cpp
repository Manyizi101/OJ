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

/*
const int maxn = 65;
const int N = 1010;
ll a[N];
int b[maxn][maxn];

int rnk(int a[][maxn], int n, int m)
{
    int ret=0;
    for(int i=0, pivot = 0; i<n&&pivot<m; ++pivot)
    {
        for(int x = 0; x<n; ++x)
        {
            for(int y = 0; y<m; ++y)
            {
                printf("%d ", a[x][y]);
            }
            printf("\n");
        }
        printf("\n");
        int pos = -1;
        for(int j=i; j<n; ++j)
        {
            if(a[j][pivot]==1)
            {
                pos=j;
                break;
            }
        }
        if(pos == -1)   continue;
        if(pos != i)
        {
            for(int j = pivot; j<m; ++j)
            {
                swap(a[i][j],a[pos][j]);
            }
        }
        ++ret;
        for(int j=0; j<n; ++j)
        {
            if(a[j][pivot]&&j!=i)
            {
                for(int k=pivot; k<m; ++k)
                {
                    a[j][k]^=a[i][k];
                }
            }
        }
        i++;

    }
    return ret;
}


int main()
{
    int t,n;
    scanf("%d", &t);
    while(t--)
    {
        ll sum = 0;
        scanf("%d",&n);
        for(int i=0; i<n; ++i)
        {
            scanf("%I64d", &a[i]);
            sum^=a[i];
        }
        if(n>maxn||sum==0)
        {
            puts("Yes");
            continue;
        }
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<maxn; ++j)
            {
                b[i][j]=a[i]>>j&1;
            }
        }
        if(rnk(b,n,10)<n) puts("Yes");
        else    puts("No");
    }
}
**/


const int maxn = 1010;
const int maxm = 65;
int t,n;
ll a[maxn];
int mat[maxm][maxm];

int rnk(int mat[][maxm],int n, int m)
{
    int ret=0;
    for(int i=0, it=0; i<n&&it<m; ++it)
    {
        int pos=-1;
        for(int j=i; j<n; ++j)
        {
            if(mat[j][it])
            {
                pos=j;
                break;
            }
        }
        if(pos==-1)   continue;
        ++ret;
        if(pos!=i)
        {
            for(int j=it; j<m; ++j)
            {
                swap(mat[i][j],mat[pos][j]);
            }
        }
        for(int j=0; j<n; ++j)
        {
            if(i!=j&&mat[j][pos])
            {
                for(int k=it; k<m; ++k)
                {
                    mat[j][k]^=mat[i][k];
                }
            }
        }
        ++i;
    }
    return ret;
}

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        ll sum=0;
        memset(mat,0,sizeof(mat));
        scanf("%d", &n);
        for(int i=0; i<n; ++i)
        {
            scanf("%I64d", &a[i]);
            sum^=a[i];
        }
        if(sum==0||n>maxm)
        {
            printf("Yes\n");
            continue;
        }
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<maxm; ++j)
            {
                mat[i][j]=(a[i]>>j)&1;
            }
        }
        int ret = rnk(mat,n,maxm);
        if(ret<n)  printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
