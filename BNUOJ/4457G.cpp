#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, d, m, i, j;
    int a[10000];
    while (~scanf("%d%d", &n, &d))
    {
        int s = 0;
        memset(a, 0, sizeof(a));
        int sum = 0;
        for (i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            s += a[i];
        }
        sort(a, a + n);
        scanf("%d", &m);
        if (m == n)
            printf("%d\n", s);
        else if (m > n)
        {
            s -= (m - n) * d;
            printf("%d\n", s);
        }
        else if (m < n)
        {
            sum = 0;
            for (i = 0; i < m; i++)
                sum += a[i];
            printf("%d\n", sum);
        }
    }

    return 0;
}
