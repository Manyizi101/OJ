#include  <stdio.h>

int f(int m, int n)
{
    if(m==1) return n;
    if(n==1) return m;
    if(m>1&&n>1)    return f(m-1,n)+f(m,n-1);
    return 0;
}

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);

        printf("%d\n",f(m,n));

    return 0;
}
