/*
#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set>

using namespace std;

int bin[10000002];
int find(int x)
{
    int r=x;
    while(bin[r]!=r)
    {
        r=bin[r];
    }
    return r;
}

void merge(int x, int y)
{
    int fx,fy;
    fx=find(x);
    fy=find(y);
    if(fx!=fy)
    {
        bin[fx]=fy;
    }
}

int main()
{
    int n,x,y,i,j,l;
    while(scanf("%d", &n)!=EOF)
    {
        l=0;
        for(i=1; i<10000001; i++)
        {
            bin[i]=i;
        }
        for(i=0;i<n;i++)
        {
            scanf("%d%d", &x,&y);
            merge(x,y);
        }
        for(i=0;i<10000002;i++)
        {

        }
    }
    return 0;
}
**/

#include<stdio.h>
int fa[10000001],rank[10000001];
int findset(int x)
{
    if(x != fa[x])
        fa[x] = findset(fa[x]);
    return fa[x];
}
void unionset(int x,int y)
{
    x=findset(x);
    y=findset(y);
    if(x==y)
        return;
    if(rank[x] >= rank[y])
    {
        fa[y] = x;
        rank[x] += rank[y];
    }
    else if(rank[x] < rank[y])
    {
        fa[x] = y;
        rank[y] += rank[x];
    }
}
int main()
{
    int n,i,maxi,a,b;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<10000000;i++)
        {
            fa[i]=i;
            rank[i]=1;
        }
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&a,&b);
            unionset(a,b);
        }
        maxi=rank[0];
        for(i=1;i<10000000;i++)
            if(maxi<rank[i])
                maxi=rank[i];
        printf("%d\n",maxi);
    }
    return 0;
}
