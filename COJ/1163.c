#include   <stdio.h>

int main()
{
    int n,i;
    while(n--)
    {
        int mo[6],mianji=0;
        for (i=0;i<6;i++)
        {
            scanf("%d", &mo[i]);
            mianji += mo[i]*i*i;
        }
        printf("%d\n", mianji/36+1);
    }
    return 0;
}
