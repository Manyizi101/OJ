#include   <stdio.h>


int main()
{
    int N,M=500, i=0;
    scanf("%d", &N);
    while (M<N)
    {
        M = (int)(M * 1.2);
        i++;
    }
    printf("%d", i);
    return 0;
}
