#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;

const int INF = 10000;

int num[4], tmp[4], result[4];
int total, money;

bool success;

void DFS(int dep, int remained)
{
    if (dep == 4)
    {
        if (remained == 0)
        {
            int sum = tmp[0] + tmp[1] + tmp[2] + tmp[3];
            if (sum < total)
            {
                for (int i = 0; i < 4; i++)
                    result[i] = tmp[i];
                total = sum;
            }
            success = true;
        }
        return;
    }
    for (int j = 0; j <= num[dep]; j++)
    {
        tmp[dep] = j;
        if (dep == 0)
            DFS(dep + 1, remained - 25 * j);
        else if (dep == 1)
            DFS(dep + 1, remained - 10 * j);
        else if (dep == 2)
            DFS(dep + 1, remained - 5 * j);
        else if (dep == 3)
            DFS(dep + 1, remained - j);
    }
}

int main(int argc, char const *argv[])
{
    while (scanf("%d%d%d%d%d", &num[0], &num[1], &num[2], &num[3], &money) && (num[0] || num[1] || num[2] || num[3] || money))
    {
        total = INF;
        success = false;
        DFS(0, money);
        if (success)
            printf("Dispense %d quarters, %d dimes, %d nickels, and %d pennies.\n", result[0], result[1], result[2], result[3]);
        else
            printf("Cannot dispense the desired amount.\n");
    }
    return 0;
}