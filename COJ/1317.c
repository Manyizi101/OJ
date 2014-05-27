#include  <stdio.h>


int main()
{
    int m, i, x;
    int a[10]= {0};
    scanf("%d", &m);
    for(i=0; i<2*m; i++)
    {
        scanf("%d", &x);
        a[x-1]++;
    }
    for(i = 0;  i< m; i++)
    {
        if(a[i] != 2)
        {
            printf("WIN");
            return 0;
        }
    }
    printf("FAIL");
    return 0;
}
