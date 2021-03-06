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
    int n, m, i, j, k, t, x, y, sum;
    elem_t mat[MAXN][MAXN];
    int pre[MAXN], key[MAXN];
    while (cin >> n >> m && n)
    {
        for (i = 0; i < m; i++)
            for (j = 0; j < m; j++)
            {
                if (i == j)    mat[i][j] = 0;
                else
                {
                    mat[i][j] = inf;
                    mat[j][i] = inf;
                }
            }
        for (t = 0; t < n; t++)
        {
            cin >> x >> y;
            cin >> mat[x - 1][y - 1];
            mat[y - 1][x - 1] = mat[x - 1][y - 1];
        }
        sum = prim(m, mat, pre);
        /*
        简直无情，这样也能A= =，卧槽
        **/
        if (sum < inf) cout << sum << endl;
        else cout << '?' << endl;
    }
    return 0;
}
