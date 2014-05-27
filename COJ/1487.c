#include   <stdio.h>


int main()
{
    int T ,fen[20], Ans = 0;
    int i, j, key;
    scanf("%d", &T);
    for (i = 0; i < T; i++)
    {
        scanf("%d", &fen[i]);
    }
    for (i = 0; i < T; i++)
    {
        for (j = T-1; j > i; j--)
        {
            if(fen[i] > fen[j])
            {
                key = fen[i];
                fen[i] = fen[j];
                fen[j] = key;
            }

        }
    }
    for (i = 1; i < T-1; i++)   Ans += fen[i];
    printf("%.3f", (float)(Ans/(T-2)));
    return 0;
}
