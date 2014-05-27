#include   <stdio.h>


int main()
{
    long long i, j, T = 0;
    long long answer[10] = {0};
    long long N[10], M[10] = {0};
    scanf("%I64d", &T);
    for (i = 0; i < T; i++)   scanf("%I64d%I64d", &N[i], &M[i]);
    for (i = 0; i < T; i++)
    {
        answer[i] = M[i] - N[i] + 1;
        for (j = M[i] - N[i] + 2; j <= M[i]; j++)
        {
            answer[i] = answer[i] * j;
        }
        for (j = 1; j <= N[i]; j++)
        {
            answer[i] = answer[i] / j;
        }
        printf ("%I64d\n", answer[i]);
    }
    return 0;
}
