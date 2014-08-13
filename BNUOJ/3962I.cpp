#include  <stdio.h>

int main()
{
    int t,m,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d", &m,&n);
        if(m%2==0&&m>=2*n)  printf("YES\n");
        else    printf("NO\n");
    }
    return 0;
}
