#include  <stdio.h>

int main()
{
    int n;
    while(scanf("%d", &n)==1)
    {
        printf("%.2f\n", (float)(2*n-1)/(float)n);
    }
    return 0;
}
