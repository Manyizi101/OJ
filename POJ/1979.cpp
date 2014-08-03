#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAX 25

char tiles[MAX][MAX];
int used[MAX][MAX];
int count, w, h;

void dfs(int i, int j)
{
    count++;
    if (i > 1 && used[i - 1][j] == 0)
    {
        used[i - 1][j] = 1; dfs(i - 1, j);
    }
    if (i < h && used[i + 1][j] == 0)
    {
        used[i + 1][j] = 1; dfs(i + 1, j);
    }
    if (j > 0 && used[i][j - 1] == 0)
    {
        used[i][j - 1] = 1; dfs(i, j - 1);
    }
    if (j < w - 1 && used[i][j + 1] == 0)
    {
        used[i][j + 1] = 1; dfs(i, j + 1);
    }
}

int main(int argc, char const *argv[])
{
    int starti, startj;
    while (scanf("%d %d", &w, &h) && w != 0 && h != 0)
    {
        if (w == 0 || h == 0)
            break;
        count = 0;
        memset(used, 0, sizeof(used));
        for (int i = 1; i <= h; i++)
        {
            scanf("%s", tiles[i]);
        }
        for (int i = 1; i <= h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (tiles[i][j] == '#')
                    used[i][j] = 1;
                else if (tiles[i][j] == '@')
                {
                    used[i][j] = 1;
                    startj = j;
                    starti = i;
                }
            }
        }
        dfs(starti, startj);
        printf("%d\n", count);
    }
    return 0;
}