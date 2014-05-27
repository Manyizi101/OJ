#include  <stdio.h>

int main()
{
    int n, i;
    double a = 2.0, b = 1.0, c;
    double answer=0;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        answer += a/b;
        c = b;
        b = a;
        a = a + c;
    }
    printf("%.8lf", answer);
    return 0;
}
