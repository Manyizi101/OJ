#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#define ll long long
using namespace std;
int jl[110];
int r, c, n, t;
struct node
{
    int x, y, d;
};
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, { -1, 0}};
int Map[110][110];
struct node2
{
    int water, time;
};
node2 ans [110][110];
int in(int x, int y)
{
    if (x >= 1 && x <= r && y >= 1 && y <= c)
        return 1;
    return 0;
}
queue<node> q;
queue<node> q2;
int bfs( )
{
    node next, tmp, fen;
    int xx, yy;
    for (int ttt = 1; ttt <= t; ttt++)
    {
        for (int i = 0; i < n; i++)
        {
            xx = jl[i] / 100, yy = jl[i] % 100;
            if (Map[xx][yy] > 4)
            {
                Map[xx][yy]  = 0;
                ans[xx][yy].water =  0;
                ans[xx][yy].time  =  ttt;
                for (int j = 0; j < 4; j++)
                {
                    fen.x = xx, fen.y = yy, fen.d = j;
                    q.push(fen);
                }
            }
            else
            {
                ans[xx][yy].water = Map[xx][yy];
            }
        }
        while (!q.empty())
        {
            node tmp = q.front();
            q.pop();
            int xx = tmp.x + dir[tmp.d][0];
            int yy = tmp.y + dir[tmp.d][1];
            if (!in(xx, yy))
                continue;
            if (Map[xx][yy] == 0)
            {
                next = tmp;
                q2.push(next);
            }
            else
                Map[xx][yy] ++;
        }
        while (!q2.empty())
        {
            q.push(q2.front());
            q2.pop();
        }
    }
    return 0;
}
int main()
{

    while (cin >> r >> c >> n >> t)
    {
        memset(Map, 0, sizeof(Map));

        for (int i = 0; i < n; i++)
        {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            jl[i] = x * 100 + y;
            ans[x][y].water = z;
            ans[x][y].time = 0;
            Map[x][y] += z;
        }
        int sx, sy;
        cin >> sx >> sy;
        while (!q.empty())
            q.pop();
        node tmp;
        for (int i = 0; i < 4; i++)
        {
            tmp.x = sx, tmp.y = sy;
            tmp.d = i;
            q.push(tmp);
        }
        bfs();
        int ex, ey;
        node2 flag ;
        for (int i = 0; i < n; i++)
        {
            ex = jl[i] / 100;
            ey = jl[i] % 100;
            flag = ans[ex][ey];
            if (flag.water == 0)
            {
                cout << 0 << " " << flag.time << endl;
            }
            else
                cout << 1 << " " << flag.water << endl;
        }
    }
    return 0;
}
