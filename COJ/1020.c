#include  <stdio.h>


int main()
{
    int a,i;
    scanf("%d", &a);
    int X[a], Y[a];
    for (i = 0; i < a; i++) scanf("%d%d", &X[i], &Y[i]);
    for (i = 0; i < a; i++)
    {
        if(X[i] >= Y[i]) printf("MMM BRAINS\n");
        else    printf("NO BRAINS\n");
    }
    return 0;
}
