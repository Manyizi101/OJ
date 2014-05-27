#include  <stdio.h>

int main()
{
    int i;
    double ans=2.5,cheng=0.5;
    printf("n e\n");
    printf("- -----------\n");
    printf("0 1\n");
    printf("1 2\n");
    printf("2 2.5\n");
    for(i=3;i<10;i++)
    {
        cheng *= 1/(float)(i);
        ans += cheng;
        printf("%d %.9lf\n", i, ans);
    }
    return 0;
}
