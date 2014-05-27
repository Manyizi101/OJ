#include  <stdio.h>

int main()
{
    int c, m ,n,  every;
    scanf("%d%d%d", &c, &m, &n);
    every = (n/m)*(n/m);
    if(c%every == 0)        printf("%d", c/every);
    else    printf("%d", c/every+1);
    return 0;
}
