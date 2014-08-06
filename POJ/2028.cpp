#include <cstdio>
#include <cstdlib>
#include <cstring>

int a[110];
int N, Q;
int day, days, i, j;
int min, max;
int flag = 0;

int main(int argc, char const *argv[])
{
    while (scanf("%d%d", &N, &Q), Q != 0 || N != 0)
    {
        flag = 0;
        memset(a, 0, sizeof(a));
        min = 10000;
        max = -1;
        for (i = 0; i < N; i++)
        {
            scanf("%d", &day);
            for (j = 0; j < day; j++)
            {
                scanf("%d", &days);
                a[days] ++;
                if (a[days] >= Q)
                {
                    flag = 1;
                    if (max < a[days])
                    {
                        max = a[days];
                        min = days;
                    }
                    if (a[days] == max && min > days)
                    {
                        min = days;
                        max = a[days];
                    }
                }
            }
        }
        if (flag == 1)
        {
            printf("%d\n", min);
        }
        else
        {
            printf("0\n");
        }
    }
    return 0;
}