#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int s[200001], n, i;

int cmp(const void *a, const void *b)
{
    return (*(int *)b - * (int *)a);
}

int main(int argc, char const *argv[])
{
    while (scanf("%d", &n) && n != 0)
    {
        for (i = 0; i < n; i++) scanf("%d", &s[i]);
        qsort(s, n, sizeof(s[0]), cmp);
        int k, A, B;
        scanf("%d", &k);
        for (; k > 0; k--)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            for (i = 0; i < n; i++)
            {
                if (s[i] <= b && s[i] >= a)
                {
                    A = i + 1;
                    break;
                }
                if (i == n - 1)
                    A = 0;
            }
            for (i = n - 1; i >= 1; i--)
            {
                if (s[i] >= a && s[i] <= b)
                {
                    B = i + 1;
                    break;
                }
                if (i == 1)
                    B = 0;
            }
            printf("%d %d\n", A, B);
        }
    }
    return 0;
}