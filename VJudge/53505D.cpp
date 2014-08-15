#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;
#define MAXN 200
#define inf 100000000.0

typedef double elem_t;
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
            {
                min[i] = mat[pre[i] = k][i];
            }
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    int t, c, i, j;
    double sum;
    elem_t mat[MAXN][MAXN];
    double x[MAXN], y[MAXN];
    int pre[MAXN];
    cin >> t;
    while (t--)
    {
        cin >> c;
        sum = 0;
        for (i = 0; i < c; i++)
            for (j = 0; j < c; j++)
            {
                if (i == j)    mat[i][j] = 0;
                else    mat[i][j] = inf;
            }
        for (i = 0; i < c; i++)
            cin >> x[i] >> y[i];
        if (c == 1)
        {
            cout << 0.0 << endl;
            continue;
        }
        for (i = 0; i < c; i++)
            for (j = c - 1; j >= i; j--)
                mat[i][j] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
        sum = prim(c, mat, pre);
        if (sum <= 1000 && sum >= 10)  printf("%.1f\n", sum * 100);
        else cout << "oh!" << endl;
    }
    return 0;
}