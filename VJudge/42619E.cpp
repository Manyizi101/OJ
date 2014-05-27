#include<iostream>
#include<stdio.h>
using namespace std;
const int Max = 100002;

int parent[Max];
bool flag[Max];

void make_set()
{
    for(int x = 1; x < 100002; x ++)
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
    int x, y = 1, fir;
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
