#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i, n, sum = 0;
    char a[30][30];
    while (scanf("%d", &n) != EOF, n)
    {
        for (i = 0; i < n; i++)
            scanf("%s", a[i]);
        printf("SET %d\n", ++sum);
        for (i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                printf("%s\n", a[i]);
            }
        }
        for (i = n - 1; i >= 0; i--)
        {
            if (i % 2 != 0)
            {
                printf("%s\n", a[i]);
            }
        }
    }
    return 0;
}