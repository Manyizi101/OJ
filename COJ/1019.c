#include   <stdio.h>


int main()
{
    long long i, j, n;
    long long S = 0, D = 1;
    scanf("%I64d", &n);
    for (i = 1; i < n+1; i++)
    {
        for (j = 1; j <= i ; j++)
        {
            D *= j;
        }
        S += D;
    }
    printf("%I64d", S);
    return 0;
}
