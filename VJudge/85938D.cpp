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

typedef long long int ll;
const double pi = acos(-1.0);
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
using namespace std;

const int maxn = 10;

int a[maxn][maxn], dir[8][2] = {{ -1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, { -1, 2}, { -2, 1}, { -2, -1}};
int stx, sty, edx, edy;
char tmpx, tmpy;
int ans = 0;
int vis[maxn][maxn];
int bu[maxn][maxn];

bool judge(int x, int y)
{
    if (1 <= x && x <= 8 && 1 <= y && y <= 8 && vis[x][y] == 0)    return true;
    else return false;
}

int bfs(int x, int y)
{
    bu[x][y] = 0;
    vis[x][y] = 1;
    queue<pair<int , int >  > q;
    q.push(make_pair(x, y));
    while (!q.empty())
    {
        int tx = q.front().first;
        int ty = q.front().second;
        q.pop();
        for (int i = 0; i < 8; ++i)
        {
            if (judge(tx + dir[i][0], ty + dir[i][1]))
            {
                if ((tx + dir[i][0] == edx) && (ty + dir[i][1] == edy))
                {
                    return bu[tx][ty] + 1;
                }
                else
                {
                    bu[tx + dir[i][0]][ty + dir[i][1]] = bu[tx][ty] + 1;
                    vis[tx + dir[i][0]][ty + dir[i][1]] = 1;
                    q.push(make_pair(tx + dir[i][0], ty + dir[i][1]));
                }
            }
        }
    }
    return 0;
}

int main()
{
    while (~scanf("%c%c", &tmpx, &tmpy))
    {
        printf("To get from %c%c to ", tmpx, tmpy);
        memset(vis, 0, sizeof(vis));
        memset(bu, 0, sizeof(bu));
        ans = 0;
        stx = tmpx - 'a' + 1;
        sty = tmpy - '0';
        getchar();
        scanf("%c%c", &tmpx, &tmpy);
        getchar();
        printf("%c%c takes ", tmpx, tmpy);
        edx = tmpx - 'a' + 1;
        edy = tmpy - '0';
        if (stx == edx && sty == edy)  ans = 0;
        else ans = bfs(stx, sty);
        printf("%d knight moves.\n", ans);
    }
    return 0;
}