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

const int MAXN = 30 + 10;

struct node
{
    int x, y, z;
    bool operator< (const node &t) const
    {
        if (x < t.x && y < t.y) return true;
        else return false;
    }
} block[MAXN * 3];

int n, num, kase = 0, tmp[3], dp[MAXN * 3];

bool cmp(node a, node b)
{
    if (a.y == b.y)    return a.x < b.x;
    else return a.y < b.y;
}

int main()
{
    ios::sync_with_stdio(false);
    while (cin >> n, n)
    {
        num = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 3; j++)    cin >> tmp[j];
            for (int j = 0; j < 3; j++)
            {
                block[num].x = min(tmp[(j + 0) % 3], tmp[(j + 1) % 3]);
                block[num].y = max(tmp[(j + 0) % 3], tmp[(j + 1) % 3]);
                block[num++].z = tmp[(j + 2) % 3];
            }
        }
        //cout << endl;
        sort(block, block + num, cmp);
        for (int i = 0; i < num; i++)  dp[i] = block[i].z;
        int Max = block[0].z;
        for (int i = 0; i < num - 1; i++)
        {
            for (int j = i + 1; j < num; j++)
            {
                if (block[i] < block[j])
                {
                    //cout << block[j].x << " " << block[j].y << " " << block[j].z << endl;
                    dp[j] = max(dp[j], dp[i] + block[j].z);
                    Max = max(Max, dp[j]);
                }
            }
        }
        cout << "Case " << ++kase << ": maximum height = " << Max << endl;
    }
    return 0;
}