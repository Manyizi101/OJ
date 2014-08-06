#include <stdio.h>
#include <string.h>
#define MAX 501
#define INF 0x3f3f3f3f
using namespace std;

int t, n, near[MAX], edge[MAX][MAX];

int Prim(int v0)
{
    int i, k, temp, v, dist[MAX] = {0};
    for (i = 0; i < n; i++)
    {
        near[i] = edge[v0][i];
    }
    near[v0] = 0;
    dist[v0] = 1;
    for (k = 0; k < n - 1; k++)
    {
        v = -1;
        temp = INF;
        for (i = 0; i < n; i++)
        {
            if (!dist[i] && temp > near[i])
            {
                temp = near[i];
                v = i;
            }
        }
        dist[v] = 1;
        for (i = 0; i < n; i++)
        {
            if (!dist[i] && i != v && edge[v][i] != 0 && edge[v][i] < near[i])
            {
                near[i] = edge[v][i];
            }
        }
    }
    temp = 0;
    for (i = 0; i < n; i++)
    {
        if (temp < near[i])    temp = near[i];
    }
    return temp;
}

int main(int argc, char const *argv[])
{
    int i, j;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                scanf("%d", &edge[i][j]);
        printf("%d\n", Prim(0));
    }
    return 0;
}