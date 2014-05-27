#include   <stdio.h>

/*int main()
{
    int n, i = 0;
    float a[3100], c[3100] = {0.0};
    scanf("%d", &n);
    for (i = 0; i < n; i++)     scanf("%f%f%f", &a[i], &a[n+1], &c[i]);
    a[1] = (a[0] + a[2])/2.0 - c[1];
    printf("%.2f", a[i]);
}*/


int main()
{
    int n, i = 0;
    double a[3000] = {0.0}, c[3000] = {0.0};
    scanf("%d", &n);
    scanf("%lf\n%lf", &a[0], &a[n+1]);
    for(i = 1; i <= n; i++)
    {
        scanf("%lf", &c[i]);
    }
    for(i = 1; i <= n; i++)
    {
        a[i] = (a[i-1] + a[i+1])/2 - c[i];
    }
    printf("%.2f", a[1]);
    return 0;
}
