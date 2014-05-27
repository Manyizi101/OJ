#include  <stdio.h>

int main()
{
    int  a, b, i =1;
    while(scanf("%x%x", &a, &b) != EOF)
          {
                if(a == 0 && b == 0)        return 0;
                printf("Case %d:\n", i);
                printf("%d\n", a+b);
                i++;
          }
    return 0;
}
