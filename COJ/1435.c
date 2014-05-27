#include   <stdio.h>


int main()
{
    int N, Xuan[1000], Ans;
    int key, i, j;
    while(scanf("%d", &N) && N != 0)
    {
        Ans = 0;
        for (i = 0; i < N; i++)     scanf("%d", &Xuan[i]);
        for (i = 0; i < N; i++)
        {
            for (j = N-1; j > i; j--)
            {
                if (Xuan[i] > Xuan[j])
                {
                    key = Xuan[i];
                    Xuan[i] = Xuan[j];
                    Xuan[j] = key;
                }
            }
        }
        if (N%2 == 0)
        {
            for(i = 0; i < N/2; i++)
            {
                if (Xuan[i]%2 == 0)     Ans += Xuan[i]/2;
                if (Xuan[i]%2 == 1)     Ans += Xuan[i]/2+1;
            }
        }
        if (N%2 == 1)
        {
            for(i = 0; i< N/2+1; i++)
            {
                if (Xuan[i]%2 == 0)     Ans += Xuan[i]/2;
                if (Xuan[i]%2 == 1)     Ans += Xuan[i]/2+1;
            }
        }
        printf("%d\n", Ans);
    }
    return 0;
}
