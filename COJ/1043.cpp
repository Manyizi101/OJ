#include  <stdio.h>

int main()
{
    int n;
    while(scanf("%d", &n)&&n!=0)
    {
        while(n>9)
        {
            n-=9;
        }
        printf("%d\n", n);
    }
    return 0;
}
