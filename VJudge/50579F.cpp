#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

int a[20], vis[20], isprime[45] = {0}, n;

void get_prime()
{
    int i, j;
    for (i = 2; i < 8; i++)
        if (!isprime[i])
            for (j = i * i; j < 45; j += i)
                isprime[j] = 1;
}

int dfs(int step)
{
    int i;
    if (step == n + 1 && !isprime[a[n] + a[1]])
    {
        for (i = 1; i < n; i++)
            printf("%d ", a[i]);
        printf("%d\n", a[n]);
        return 0;
    }
    for (i = 2; i <= n; i++)
    {
        if (!vis[i] && !isprime[i + a[step - 1]])
        {
            a[step] = i;
            vis[i] = 1;
            dfs(step + 1);
            vis[i] = 0;
        }
    }
}

int main(int argc, char const *argv[])
{
    int k = 1;
    a[1] = 1;
    get_prime();
    while (scanf("%d", &n) != EOF)
    {
        memset(vis, 0, sizeof(vis));
        printf("Case %d:\n", k++);
        dfs(2);
        printf("\n");
    }
}