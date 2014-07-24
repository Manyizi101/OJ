#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAX 60001

int num[MAX];
int n,k=0;

void fun()
{
    int i, j;
    memset(num, 0, sizeof(num));
    for (i = 1; i < MAX; i++)
    {
        for (j = i + i; j < MAX; j += i)
        {
            num[j] += i;
        }
    }
}

int main()
{
    fun();
    while (scanf("%d", &n) != EOF)
    {
        k++;
        if (k == 1)
            printf("PERFECTION OUTPUT\n");
        if (n == 0)
        {
            printf("END OF OUTPUT\n");
            break;
        }
        if (n / 10 == 0)
            printf("    %d", n);
        else if (n / 100 == 0)
            printf("   %d", n);
        else if (n / 1000 == 0)
            printf("  %d", n);
        else if (n / 10000 == 0)
            printf(" %d", n);
        else
            printf("%d", n);
        if (num[n] == n)
        {
            printf("  PERFECT\n");
        }
        else if (num[n] < n)
        {
            printf("  DEFICIENT\n");
        }
        else
            printf("  ABUNDANT\n");
    }
    return 0;
}