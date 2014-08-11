#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string.h>

using namespace std;
char map[100][100];
int vis[100][100];
int m, n;
int op[8][2] = {{ -1, -1}, { -1, 0}, {1, 0}, {0, 1}, {1, 1}, { -1, 1}, {1, -1}, {0, -1}};

void search(int x, int y)
{
    vis[x][y] = -1;
    for (int i = 0; i < 8; i++)
        if ((x + op[i][0] >= 0) && (x + op[i][0] < m) && (y + op[i][1] >= 0) && (y + op[i][1] < n) && (vis[x + op[i][0]][y + op[i][1]] != -1) && map[x + op[i][0]][y + op[i][1]] == '@')
            search(x + op[i][0], y + op[i][1]);
}

int main(int argc, char const *argv[])
{
    int i, j, sum;
    while (scanf("%d %d", &m, &n) && m)
    {
        sum = 0;
        for (i = 0; i < m; i++)
            for (j = 0; j < n; j++)
                cin >> map[i][j];
        memset(vis, 0, sizeof(vis));
        for (i = 0; i < m; i++)
            for (j = 0; j < n; j++)
                if (vis[i][j] != -1 && map[i][j] == '@')
                {
                    sum++;
                    search(i, j);
                }
        printf("%d\n", sum);
    }
    system("pause");
    return 0;
}
