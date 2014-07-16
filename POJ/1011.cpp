#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int sticks[64], n, len, num, sum;
bool used[64];
bool end;

bool compare(int a, int b)
{
    return a > b;
}

bool dfs(int cur, int left, int level)
{
    if (left == 0)
    {
        if (level == num - 2)
            return true;
        for (cur = 0; used[cur]; cur++);
        used[cur] = true;
        if (dfs(cur + 1, len - sticks[cur], level + 1))
            return true;
        used[cur] = false;
        return false;
    }
    else
    {
        if (cur >= n - 1)
            return false;
        for (int i = cur; i < n; i++)
        {
            if (used[i])
                continue;
            if ((sticks[i] == sticks[i - 1]) && !used[i - 1])
                continue;
            if (sticks[i] > left)
                continue;
            used[i] = true;
            if (dfs(i, left - sticks[i], level))
                return true;
            used[i] = false;
        }
        return false;
    }
}

int main(int argc, char const *argv[])
{
    while (cin >> n)
    {
        if (n == 0)
            break;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &sticks[i]);
            sum += sticks[i];
        }
        sort(sticks, sticks + n, compare);
        end = false;
        for (len = sticks[0]; len <= sum / 2; len++)
        {
            if (sum % len == 0)
            {
                used[0] = true;
                num = sum / len;
                if (dfs(0, len - sticks[0], 0))
                {
                    end = true;
                    printf("%d\n", len);
                    break;
                }
                used[0] = false;
            }
        }
        if (!end)
            printf("%d\n", sum);
        memset(used, 0, sizeof(used));
    }
    return 0;
}
