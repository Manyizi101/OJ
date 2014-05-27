#include   <stdio.h>

int main()
{
    int N,i;
    scanf("%d", &N);
    char a[N+1];
    for(i=0;i<N+1;i++)    scanf("%c", &a[i]);
    for(i=0;i<N+1;i++)
    {
        if(a[i]=='0') printf("1");
        if(a[i]=='1') printf("0");
    }
    return 0;
}
