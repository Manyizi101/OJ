#include<cstdio>
int data[50001], s[50001], T[50001];

inline int lowbit(int t)
{
    return t & (-t);
}

inline int sum(int end)
{
    int sum = 0;
    while (end > 0)
    {
        sum += T[end];
        end -= lowbit(end);
    }
    return sum;
}

inline void plus(int pos, int num, int count)
{
    while (pos <= count)
    {
        T[pos] += num;
        pos += lowbit(pos);
    }
}

int main()
{
    char buffer[10];
    int i, j, t, n, a, b;
    scanf("%d", &t);
    for (i = 1; i <= t ; i++)
    {
        scanf("%d", &n);
        T[0] = s[0] = data[0] = 0;
        for (j = 1; j <= n ; j++)
        {
            scanf("%d", &data[j]);
            s[j] = s[j - 1] + data[j];
            T[j] = s[j] - s[j - lowbit(j)];
        }
        printf("Case %d:\n", i);
        while (scanf("%s", buffer) == 1 && buffer[0] != 'E')
        {
            scanf("%d%d", &a, &b);
            switch (buffer[0])
            {
            case 'Q':
                printf("%d\n", sum(b) - sum(a) + data[a]); break;
            case 'A':
                plus(a, b, n); data[a] += b;    break;
            case 'S':
                plus(a, -b, n); data[a] -= b;   break;
            }
        }
    }
}
