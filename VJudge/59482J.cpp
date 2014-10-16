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
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<28)
#define ll long long int
using namespace std;

#define MAXN 50000+10
#define TREE_SIZE 50000+10



class IntervalTree
{
private:
    int Cover[TREE_SIZE],Top[TREE_SIZE];
    int size;
    int _Query(int a, int b, int l,int r, int Ind)
    {
        if(a<=l&&b>=r)  return Top[Ind];
        int mid=(l+r)>>1,ret=Cover[Ind];
        if(a<=mid)  ret=max(ret, _Query(a,b,l,mid,Ind<<1));
        if(b>mid)   ret=max(ret,_Query(a,b,mid+1,r,(Ind<<1)+1));
        return ret;
    }
    void _Modify(int a,int l,int r,int Ind, int d)
    {
        if(l==r&&l==a)
        {
            Cover[Ind]=Top[Ind]=d;
            return;
        }
        int mid=(l+r)>>1;
        if(a<=mid)  _Modify(a,l,mid,Ind<<1,d);
        else _Modify(a,mid+1,r,(Ind<<1)+1,d);
        Top[Ind]=max(Top[Ind<<1],Top[(Ind<<1)+1]);
    }
public:
    IntervalTree()
    {
        memset(Cover,0,sizeof(Cover));
        memset(Top,0,sizeof(Top));
        size=(TREE_SIZE>>2)-1;
    }
    IntervalTree(int size):size(size)
    {
        memset(Cover,0,sizeof(Cover));
        memset(Top,0,sizeof(Top));
    }
    int Query(int a,int b)
    {
        return _Query(a,b,1,size,1);
    }
    void Modify(int a,int d)
    {
        return _Modify(a,1,size,1,d);
    }
};


int t,n,st,ed,q;

int a[MAXN];
int tmp;
IntervalTree dp;

int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}

void init()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &a[i]);
    }
    for(int i=1; i<=n-1; i++)
    {
        dp.Modify(i,gcd(a[i],a[i+1]));
    }
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        init();
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d%d", &st,&ed);
            printf("%d\n", dp.Query(st,ed-1));
        }
    }
}
