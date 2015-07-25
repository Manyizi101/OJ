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


const int MAX = 10240;
const int INF = 65536;

int N, M;
int f[MAX][MAX], pMap[MAX][MAX];

void Floyd()
{
    int nLen = 65536;
    for (int k = 1; k <= N; k++) // 最外层必须是k
    {

        for (int i = 1; i <= k; i++) // 求解最小环
        {
            for (int j = 1; j <= k; j++)
            {
                nLen = min(nLen, pMap[i][j] + f[i][k] + f[k][j]);
            }
        }

        for (int i = 1; i <= N; i++) // 求解APSP
        {
            for (int j = 1; j <= N; j++)
            {
                if (f[i][k] + f[k][j] < f[i][j]) // 是否需要松弛
                {
                    f[i][j] = f[i][k] + f[k][j];
                }
            }
        }
    }

    cout << "Shortest Loop is " << nLen << endl;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (f[i][j] == INF)
            { cout << "-1 "; }
            else
            { cout << f[i][j] << " "; }
        }
        cout << endl;
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            pMap[i][j] = f[i][j] = (i == j) ? 0 : INF;  // 初始化
        }
    }
    for (int i = 1; i <= M; i++)
    {
        int s, e, v;
        cin >> s >> e >> v;
        pMap[s][e] = v; pMap[e][s] = v;     // 无向图
        f[s][e] = v; f[e][s] = v;
    }
    Floyd();
    return 0;
}

