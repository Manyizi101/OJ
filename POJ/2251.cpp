#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <fstream>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<28)
#define MAXN 35
using namespace std;

typedef pair<int, int, int> P;

char maze[MAXN][MAXN][MAXN];
int vis[MAXN][MAXN][MAXN];
int l, r, c;
int dx[6] = { -1, 0, 1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};



void init()
{
    memset(maze, 0, sizeof(maze));
    for (int i = 1; i <= l; i++)
        for (int j = 1; j <= r; j++)
            cin >> maze[i][j] + 1;
}

int bfs(int x, int y, int z)
{
    queue<P> que;
    que.push(P(z, y, x));
    vis[z][y][x] = 1;
    while (que.size())
    {
        P p = que.front(); que.pop();
        if (maze[p.third][p.second][p.first] == 'E')   break;
        for (int i = 0; i < 6; i++)
        {
            int nx = p.third + dz[i], ny = p.second + dy[i], nz = p.first + dx[i];
            if (maze[nz][ny][nx] != '.' && !vis[nz][ny][nx])
            {
                que.push(P(nz, ny, nx));
                vis[nz][ny][nx] = 1;
            }
        }
    }
}