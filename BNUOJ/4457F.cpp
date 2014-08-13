#include<stdio.h>
#include<math.h>

int num[10000001];

int main(int argc, char const *argv[])
{
    int n, i, t;
    double d;
    for (i = 1, d = 0; i < 10000001; i++)
    {
        d += log10(i);
        num[i] = (int)d + 1;
    }
    while(scanf("%d", &n)!=EOF)
    {
        printf("%d\n", num[n]);
    }
}