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

#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
typedef long long int ll;
const int N = 1e5+100;
typedef pair<int,int >pii;
int d[N<<2];
int a[N];
pii b[N];
int gcd(int a,int b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}
void pushup(int rt)
{
    d[rt]=gcd(d[rt<<1],d[rt<<1|1]);
}
void build(int l,int r,int rt)
{
    if(l==r)
    {
        d[rt]=a[l];
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
int query(int L,int R,int l,int r,int rt)
{
    if(L<=l&&r<=R) return d[rt];
    int m=(l+r)>>1;
    int x,y;
    x=y=0;
    if(L<=m) x=query(L,R,lson);
    if(R>m) y=query(L,R,rson);
    return gcd(x,y);
}

int main()
{
    int n,t;
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i],b[i].first=a[i],b[i].second=i;
    build(root);
    sort(b+1,b+1+n);
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        int gd=query(l,r,root);
        int fr=lower_bound(b+1,b+n+1,pii(gd,l))-(b+1);
        int ba=lower_bound(b+1,b+1+n,pii(gd,r+1))-(b+1);
        printf("%d\n",(r-l+1)-(ba-fr));
    }

}
