#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <queue>
using namespace std;
#define Mod 1000000007

struct Point
{
    int x, y;
    int step;
} S;

char mp[13][13];
int vis[13][13];
int n, m;
int lef;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int t, cs = 1, i, j, k, h;
queue<Point> que;

bool judge(int nx, int ny)
{
    if (nx < n && nx >= 0 && ny < m && ny >= 0)
        return true;
    return false;
}

int BFS()
{
    int maxi = 0;
    while (!que.empty())
    {
        int SIZE = que.size();
        while (SIZE--)
        {
            Point tmp = que.front();
            que.pop();
            int nx = tmp.x;
            int ny = tmp.y;
            int step = tmp.step;
            maxi = max(maxi, step);
            Point now;
            for (int k = 0; k < 4; k++)
            {
                int kx = nx + dx[k];
                int ky = ny + dy[k];
                if (!judge(kx, ky) || vis[kx][ky])
                    continue;
                if (mp[kx][ky] == '#')
                {
                    vis[kx][ky] = 1;
                    now.x = kx;
                    now.y = ky;
                    now.step = step + 1;
                    que.push(now);
                    lef--;
                }
            }
        }
    }
    if (lef == 0)
        return maxi;
    else
        return -1;
}

int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        int cnt = 0;
        for (i = 0; i < n; i++)
        {
            scanf("%s", mp[i]);
            for (j = 0; j < m; j++)
                if (mp[i][j] == '#')
                    cnt++;
        }
        int flag = 0;
        int tag = Mod;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                if (mp[i][j] == '#')
                {
                    for (k = i; k < n; k++)
                    {
                        for (h = (k == i ? j : 0); h < m; h++)
                        {
                            if (mp[k][h] == '#')
                            {
                                memset(vis, 0, sizeof(vis));
                                S.x = i, S.y = j, S.step = 0;
                                que.push(S);
                                lef = cnt - 1;
                                vis[i][j] = 1;
                                if (!(i == k && j == h))
                                {
                                    S.x = k, S.y = h, S.step = 0;
                                    que.push(S);
                                    vis[k][h] = 1;
                                    lef--;
                                }
                                int res = BFS();
                                if (res != -1)
                                {
                                    flag = 1;
                                    tag = min(tag, res);
                                }
                            }
                        }
                    }
                }
            }
        }
        if (flag)
            printf("Case %d: %d\n", cs++, tag);
        else
            printf("Case %d: -1\n", cs++);
    }
    return 0;
}