#include <iostream>
#include <cstdio>
using namespace std;

char chess[10][10];
int visited[10][10];
int X[4] = { -1, 1, 1, -1};
int Y[4] = {1, 1, -1, -1};
int remain;
int i,j;

int judge(int x, int y, int n)
{
    int i, j;
    for (i = x, j = 0; j < n; j++)    visited[i][j] = 1;
    for (j = y, i = 0; i < n; i++)    visited[i][j] = 1;
}

void dfs(int x, int y, int n)
{
    judge(x, y, n);
    for (i = 0; i < 4; i++)
        if (visited[x + X[i]][y + Y[i]] == 0)
        {
            dfs(x + X[i], y + Y[i], n);
            remain--;
        }
}

int main(int argc, char const *argv[])
{
    int n, k, ans;
    while (cin >> n >> k && n != -1 && k != -1)
    {
        memset(visited, 1, sizeof(visited));
        ans = 0;
        remain = k;
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
            {
                scanf("%c", &chess[i][j]);
                if (chess[i][j] == '#')    visited[i][j] = 0;
            }
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
            {
                dfs(i, j, n);
                if (remain == 0)
                {
                    remain = k;
                    ans++;
                    break;
                }
            }
        cout << ans << endl;
    }
    return 0;
}