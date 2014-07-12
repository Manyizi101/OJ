#include <cstdio>
#include <cmath>
using namespace std;

int N, S, M;
int end, min;

int dfs(int v, int m, int lastr, int lasth)
{
    if (m == 0)
    {
        if (v > 0 || v < 0)
            return 0;
        else
        {
            end = 1;
            if (min < S)
                S = min;
            return 0;
        }
    }
    int i, t = 0, j, k, temp;
    for (i = 1; i <= m; i++)
        t += i * i * i;
    if (v < t)
        return 0;
    t -= m * m * m;
    int maxr, maxh;
    maxr = (int)sqrt((v - t) * 1.0 / m) < lastr ? (int)sqrt((v - t) * 1.0 / m) : lastr;
    for (i = maxr; i >= m; i--)
    {
        maxh = (v - t) / (i * i) < lasth ? (v - t) / (i * i) : lasth;
        for (j = maxh; j >= m; j--)
        {
            temp = 0;
            for (k = 0; k <= m - 1; k++)
                temp += (i - k) * (i - k) * (j - k);
            if (v > temp)
                break;
            int tempv = v - i * i * j;
            if (m == M)
            {
                if (i * i < S)
                    min = i * i;
                else
                {
                    tempv = v;
                    continue;
                }
            }
            min += 2 * i * j;
            if (min > S)
            {
                tempv = v;
                min -= 2 * i * j;
                continue;
            }
            dfs(tempv, m - 1, i - 1, j - 1);
            min -= 2 * i * j;
        }
    }
    return 0;
}


int main(int argc, char const *argv[])
{
    while (scanf("%d%d", &N, &M) == 2)
    {
        int t = 0;
        end = 0;
        S = 100000;
        dfs(N, M, 1000, 1000);
        if (!end)
            S = 0;
        printf("%d\n", S);
    }
    return 0;
}