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
#define inf (1<<30)
#define MAXN 110
using namespace std;

int n, m;
char field[MAXN][MAXN + 1];

void dfs(int x, int y)
{
    field[x][y] = '.';
    for (int dx = -1; dx <= 1; dx++)
    {
        for (int dy = -1; dy <= 1; dy++)
        {
            int nx = x + dx, ny = y + dy;
            if (0 <= nx && nx < n && 0 <= ny && ny < m && field[nx][ny] == 'W')
                dfs(nx, ny);
        }
    }
    return;
}

int main(int argc, char const *argv[])
{

    int res = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> field[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (field[i][j] == 'W')
            {
                dfs(i, j);
                res++;
            }
        }
    }
    cout << res << endl;
    return 0;
}
