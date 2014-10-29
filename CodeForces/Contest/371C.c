#include  <stdio.h>
#include  <string.h>


int main()
{
    char a[100];
    int h[3]= {0,0,0},n[3],p[3],len;
    int i;
    long long int money=0,ans=0;
    scanf("%s", a);
    len = strlen(a);
    scanf("%d%d%d%d%d%d%I64d",&n[0],&n[1],&n[2],&p[0],&p[1],&p[2],&money);
    for(i=0; i<len; i++)
    {
        if(a[i]=='B')   h[0]++;
        if(a[i]=='S')   h[1]++;
        if(a[i]=='C')   h[2]++;
    }
    while(n[0]>=h[0]&&n[1]>=h[1]&&n[2]>=h[2])
    {
        n[0]-=h[0];
        n[1]-=h[1];
        n[2]-=h[2];
        ans++;
    }
    if(n[0]!=0&&n[1]!=0&&n[2]!=0)
    {

        ans++;
    }
    printf("%I64d", ans);
    return 0;
}
