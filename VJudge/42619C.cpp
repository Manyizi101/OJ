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

int bin[1002];

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
    int i,x,y,count;
    while(scanf("%d%d", &x,&y),x!=-1&&y!=-1)
    {
        for(i=1; i<=n; i++)
        {
            bin[i]=i;
        }
        merge(x,y);
        if(bin[i]==i)
        printf("%d\n",count);
    }
    return 0;
}
**/


#include<iostream>
#include<stdio.h>
using namespace std;
const int Max = 105;

int parent[Max];
bool flag[Max];

void make_set(){
    for(int x = 1; x < 100; x ++){
        parent[x] = x;
        flag[x] = false;
    }
}

int find_set(int x){
    if(x != parent[x])
        parent[x] = find_set(parent[x]);
    return parent[x];
}

void union_set(int x, int y){
    x = find_set(x);
    y = find_set(y);
    if(x == y) return;
    parent[y] = x;
}

int main(){
    int x, y, t = 1, fir;
    while(scanf("%d %d", &x, &y) != EOF){
        if(x == -1 && y == -1) break;
        if(x == 0 && y == 0){
            printf("Case %d is a tree.\n", t ++);
            continue;
        }
        make_set();
        flag[x] = flag[y] = true;
        fir = x;
        bool tree = true;
        if(x == y) tree = false;
        else union_set(x, y);
        while(scanf("%d %d", &x, &y) && x != 0){
            flag[x] = flag[y] = true;
            if(find_set(x) == find_set(y)) tree = false;   //  第2类判断。
            union_set(x, y);
        }
        for(x = 1; x < 100; x ++)
            if(flag[x] && find_set(x) != find_set(fir))
                tree = false;
        if(tree) printf("Case %d is a tree.\n", t ++);
        else printf("Case %d is not a tree.\n", t ++);
    }
    return 0;
}
