#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
#define MAXN 200
#define inf 1000000000

typedef int elem_t;

elem_t prim(int n, elem_t mat[][MAXN], int *pre)
{
    elem_t min[MAXN], ret = 0;
    int v[MAXN], i, j, k;
    for (i = 0; i < n; i++)
        min[i] = inf, v[i] = 0, pre[i] = -1;
    for (min[j = 0] = 0; j < n; j++)
    {
        for (k = -1, i = 0; i < n; i++)
            if (!v[i] && (k == -1 || min[i] < min[k]))
                k = i;
        for (v[k] = 1, ret += min[k], i = 0; i < n; i++)
            if (!v[i] && mat[k][i] < min[i])
                min[i] = mat[pre[i] = k][i];
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    int n, i, j, k, cnt, x, sum;
    char ch;
    int pre[MAXN];
    elem_t mat[MAXN][MAXN];
    while (cin >> n && n)
    {
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
            {
                mat[i][j] = inf;
                if(i==j)    mat[i][j]=0;
            }
        for (i = 0; i < n - 1; i++)
        {
            cin >> ch >> cnt;
            for (j = 0, k = int(ch - 'A'); j <= cnt - 1; j++)
            {
                cin >> ch >> x;
                mat[k][int(ch - 'A')] = x;
                mat[int(ch - 'A')][k] = x;
            }
        }
        sum = prim(n, mat, pre);
        cout<<sum<<endl;
    }
    return 0;
}
