#include <iostream>
#include <cstring>
using namespace std;

int i, j;
int map[110][110];

int main()
{
    int n;
flag:
    while (cin >> n && n != 0)
    {
        memset(map, 0, sizeof(map));
        int x, y;
        for (i = 1; i <= n - 1; i++)
            for (j = 1; j <= n; j++)
            {
                cin >> x >> y;
                map[y][x] = i;
            }
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
            {
                if (map[i][j] == 0)    map[i][j] = n;
            }
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
            {
                if (!(map[i][j] == map[i - 1][j] || map[i][j] == map[i][j + 1] || map[i][j] == map[i + 1][j] || map[i][j] == map[i][j - 1]))
                {
                    cout << "wrong" << endl;
                    goto flag;
                }
            }

        cout << "good" << endl;
        goto flag;
    }
    return 0;
}