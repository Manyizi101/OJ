#include <stdio.h>

int main()
{
    int a, b, n, longest, tmp;
    while (scanf("%d%d", &a, &b) != EOF)
    {
        printf("%d %d ", a, b);
        if (a > b)
        {
            tmp = a;
            a = b;
            b = tmp;
        }
        longest = n = 1;
        for (int i = a; i <= b; i++)
        {
            tmp = 1;
            n = i;
            while (n-1)
            {
                n % 2 == 0 ? (n = n / 2) : (n = 3 * n + 1);
                tmp++;
            }
            if (tmp > longest)
            {
                longest = tmp;
            }
        }
        printf("%d\n", longest);
    }
    return 0;
}