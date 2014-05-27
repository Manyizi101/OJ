#include  <stdio.h>

int main()
{
    int v,u,s;
    while(scanf("%d%d%d", &v,&u,&s))
    {
        if(v==0&&u==0&&s==0)    return 0;
        printf("%.3f\n", s/(float)(v)-s/(float)(u));
    }
}
