/*
#include   <stdio.h>
#include   <math.h>


int main()
{
    int n;
    scanf("%d", &n);
    printf("%ld", (long)(pow(((1+sqrt(5.0))/2),n) /sqrt(5.0) - pow(((1-sqrt(5.0))/2),n) /sqrt(5.0)) );
    return 0;
}

**/


#include   <stdio.h>


int main()
{
    int n, i, a[100] = {1};
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        a[i+2] = a[i] + a[i+1];
    }
    printf("%d", a[n+1]);
    return 0;
}
