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
    /* code */
    return 0;
}
