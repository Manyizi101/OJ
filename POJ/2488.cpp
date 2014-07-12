#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int visited[7][7];
int X[4] = { -2, 2, 2, -2};
int Y[4] = {2, 2, -2, -2};

int go(int x, int y, int p, int q)
{
    if (visited[x][y] == 1 && 0 < x && x < p+1 && 0 < y && y < q+1)    return 1;
    else return 0;
}

void dfs(int x, int y)
{
    visited[x][y] = 1;
    for (i = 0; i < 4; i++)
        if (go(x + X[i], y + Y[i]))
            dfs(x + X[i], y + Y[i]);

}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    while (n--)
    {
        int p, q, i, j;
        memset(visited, 0, sizeof(visited));
        cin >> p >> q;
        for (i = 0, j = 0; i < p+2; i++)    visited[i][j] = 1;
        for (i = 0, j = 0; j < q+2; j++)    visited[i][j] = 1;
        dfs(p,q);
    }
    return 0;
}
