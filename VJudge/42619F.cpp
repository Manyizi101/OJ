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

int bin[1000002];

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
    int n,bugs,inter,x,y,i,j=0;
    bool ans;
    scanf("%d", &n);
    while(n--)
    {
        ans=false;
        j++;
        for(i=1; i<1000001; i++)
        {
            bin[i]=i;
        }
        scanf("%d%d", &bugs, &inter);
        for(i=1; i<=inter; i++)
        {
            scanf("%d%d", &x, &y);
            merge(x,y);
            if(find(x)==find(y))
            {
                ans=true;
            }
        }
        if(ans=true)
        {
            printf("Scenario #%d:", j);
            printf("Suspicious bugs found!\n");
        }
        else
        {
            printf("Scenario #%d:", j);
            printf("No suspicious bugs found!\n");
        }
    }
    return 0;
}

**/


/*
#include<iostream>
#include<stdio.h>
using namespace std;
const int Max = 1000002;

int parent[Max];
bool flag[Max];

void make_set()
{
    for(int x = 1; x < 1000002; x ++)
    {
        parent[x] = x;
        flag[x] = false;
    }
}

int find_set(int x)
{
    if(x != parent[x])
        parent[x] = find_set(parent[x]);
    return parent[x];
}

void union_set(int x, int y)
{
    x = find_set(x);
    y = find_set(y);
    if(x == y) return;
    parent[y] = x;
}

int main()
{
    int x, y = 1, fir,n;
    while(scanf("%d %d", &x, &y) != EOF)
    {
        if(x == -1 && y == -1) break;
        if(x == 0 && y == 0)
        {
            printf("Yes\n");
            continue;
        }
        make_set();
        flag[x] = flag[y] = true;
        fir = x;
        bool tree = true;
        if(x == y) tree = false;
        else union_set(x, y);
        while(scanf("%d %d", &x, &y) && x != 0)
        {
            flag[x] = flag[y] = true;
            if(find_set(x) == find_set(y)) tree = false;
            union_set(x, y);
        }
        for(x = 1; x < 100; x ++)
            if(flag[x] && find_set(x) != find_set(fir))
                tree = false;
        if(tree) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
**/


#include <algorithm>
#include <cstdio>

using namespace std;

const int MAXN = 4444;

int f[MAXN], s[MAXN];

int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}

inline void merge(int x, int y) {
    if (x == y)
        return;
    if (s[x] < s[y])
        swap(x, y);
    f[y] = x;
    s[x] += s[y];
}

int main() {
    int t;
    scanf("%d", &t);
    for (int k = 1; k <= t; ++k) {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n << 1; ++i) {
            f[i] = i;
            s[i] = 1;
        }
        bool b = false;
        while (m--) {
            int x, y;
            scanf("%d%d", &x, &y);
            int fx = find(x), fy = find(y);
            if (fx == fy)
                b = true;
            else {
                merge(fx, find(y + n));
                merge(fy, find(x + n));
            }
        }
        //if (k > 1)
            //putchar('\n');
        printf("Scenario #%d:\n", k);
        puts(b ? "Suspicious bugs found!\n" : "No suspicious bugs found!\n");
    }
    return 0;
}
