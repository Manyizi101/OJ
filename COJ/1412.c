#include   <stdio.h>


int main()
{
    int N, i, Ans = 1;
    while(scanf("%d", &N) != EOF)
    {
        Ans = 1;
        for (i = 1; i <= N; i++)
        {
            Ans *= i;
        }
        printf("%d\n", Ans);
    }
    return 0;
}
