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
#define debug "output for debug\n"
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf 0x3f3f3f3f
#define ll long long int
using namespace std;

#define MAXN 200000+10

int n,m;

struct node
{
    int a,b,w;
}q[MAXN];

int print(int k)
{
    for(int i=1;i<=m;i++)
    {
        int x=q[i].a;
        int y=q[i].b;
        int va=x<0?-x>k:q[x].w;
        int vb=y<0?-y>k:q[y].w;
        q[i].w=!(va&&vb);
    }
    return q[m].w;
}

int solve(int vn)
{
    int l=1,r=n;
    while(l<r)
    {
        int mid=l+(r-l)/2;
        if(print(mid)==vn)    r=mid;
        else l=mid+1;
    }
    return l;
}

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while(t--)
    {
        scanf("%d%d", &n,&m);
        for(int i=1;i<=m;i++)   scanf("%d%d",&q[i].a,&q[i].b);
        int v0=print(0);
        int vn=print(n);
        if(v0==vn)
        {
            for(int i=1;i<=n;i++)   printf("0");
        }
        else
        {
            int x=solve(vn);
            for(int i=1;i<x;i++)    printf("0");
            printf("x");
            for(int i=x+1;i<=n;i++) printf("1");
        }
        printf("\n");
    }
	return 0;
}
