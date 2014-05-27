#include  <stdio.h>

int main()
{
    int N, K, i, k, key;
    int grade[102] = {0};
    scanf("%d%d", &N, &K);
    for (i = 0; i< N; i++)  scanf("%d", &grade[i]);
    for (i = 0; i < N; i++)
    {
        for(k = N; k > i; k--)
        {
            if(grade[i] < grade[k])
            {
                key = grade[i];
                grade[i] = grade[k];
                grade[k] = key;
            }
        }
    }
    printf("%d %d", grade[0], grade[K-1]);
    return 0;
}
