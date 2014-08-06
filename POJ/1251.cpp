#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 26

typedef struct
{
    int x, y;
    int w;
} edge;

edge e[MAX *MAX];
int rank[MAX];
int father[MAX];
int sum;


bool cmp(const edge a, const edge b)
{
    return a.w < b.w;
}


void Make_Set(int x)
{
    father[x] = x;
    rank[x] = 0;
}


int Find_Set(int x)
{
    if (x != father[x])
    {
        father[x] = Find_Set(father[x]);
    }
    return father[x];
}


void Union(int x, int y, int w)
{

    if (x == y) return;
    if (rank[x] > rank[y])
    {
        father[y] = x;
    }
    else
    {
        if (rank[x] == rank[y])
        {
            rank[y]++;
        }
        father[x] = y;
    }
    sum += w;
}

int main()
{
    int i, j, k, m, n, t;
    char ch;
    while (cin >> m && m != 0)
    {
        k = 0;
        for (i = 0; i < m; i++) Make_Set(i);
        for (i = 0; i < m - 1; i++)
        {
            cin >> ch >> n;
            for (j = 0; j < n; j++)
            {
                cin >> ch >> e[k].w;
                e[k].x = i;
                e[k].y = ch - 'A';
                k++;
            }
        }
        sort(e, e + k, cmp);
        sum = 0;
        for (i = 0; i < k; i++)
        {
            Union(Find_Set(e[i].x), Find_Set(e[i].y), e[i].w);
        }
        cout << sum << endl;
    }
    return 0;
}